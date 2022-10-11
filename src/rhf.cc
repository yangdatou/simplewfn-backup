#include <iostream>
#include <string>
#include <cassert>

#include "utils.h"

const double TOL = 1e-8;
const int MAX_ITER = 100;

extern "C" void test_rhf(int nao, int nelec_alph, int nelec_beta, double *s1e, double *h1e, double *h2e) {
    std::cout << "Armadillo version: " << arma::arma_version::as_string() << std::endl;
    std::cout << "nao = " << nao << std::endl;
    std::cout << "nelec_alph = " << nelec_alph << std::endl;
    std::cout << "nelec_beta = " << nelec_beta << std::endl;

    Int1eAO s1e_ao = build_int1e_ao(s1e, nao);
    Int1eAO h1e_ao = build_int1e_ao(h1e, nao);
    Int2eAO h2e_ao = build_int2e_ao(h2e, nao);

    print_matrix(s1e_ao, "Overlap Matrix");
    print_matrix(h1e_ao, "One-electron Hamiltonian Matrix");
}

// double solve_rhf(int nao, int nelec_alph, int nelec_beta, double *s1e, double *h1e, double *h2e) {
//     test_rhf(nao, nelec_alph, nelec_beta, s1e, h1e, h2e);
//     return 0.0;
// }