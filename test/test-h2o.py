import ctypes
import numpy
import pyscf

def test_h2o(basis='ccpvdz'):
    mol = pyscf.M(
        atom = 'O 0 0 0; H 0 -0.757 0.587; H 0 0.757 0.587',
        basis = basis, symmetry = False,
    )
    nelec_alph = mol.nelec[0]
    nelec_beta = mol.nelec[1]
    
    nao  = mol.nao_nr()
    s1e  = mol.intor('int1e_ovlp')

    kin  = mol.intor('int1e_kin')
    nuc  = mol.intor('int1e_nuc')

    h1e  = kin + nuc
    h2e  = mol.intor('int2e', aosym=4)

    num_pair = nao * (nao + 1) // 2
    num_h2e  = num_pair * (num_pair + 1) // 2

    assert s1e.shape == (nao, nao)
    assert h1e.shape == (nao, nao)
    assert h2e.shape == (num_h2e,)

    simplewfn_rhf = numpy.ctypeslib.load_library("rhf", "./bin/")

    simplewfn_rhf.test_rhf(
        ctypes.c_int(nao), 
        ctypes.c_int(nelec_alph),
        ctypes.c_int(nelec_beta),
        s1e.ctypes.data_as(ctypes.c_void_p),
        h1e.ctypes.data_as(ctypes.c_void_p),
        h2e.ctypes.data_as(ctypes.c_void_p),
    )

if __name__ == '__main__':
    test_h2o()