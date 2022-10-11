import ctypes

import pyscf
from pyscf.lib.misc import load_library

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
    h2e  = mol.intor('int2e')

    assert s1e.shape == (nao,nao)
    assert h1e.shape == (nao,nao)
    assert h2e.shape == (nao, nao, nao, nao)

    simplewfn_rhf = load_library('./bin/rhf')

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