#include <iostream>
#include <string>
#include <cassert>

#define ARMA_ALLOW_FAKE_GCC
#include <armadillo>

#include "utils.h"

const double TOL = 1e-8;
const int MAX_ITER = 100;

extern "C" void test_rhf(int nao, int nelec_alph, int nelec_beta, double *s1e, double *h1e, double *h2e) {
    std::cout << "Armadillo version: " << arma::arma_version::as_string() << std::endl;

    auto nmo = nao;

    auto s1e_ao = build_int1e_ao(s1e, nao);
    auto h1e_ao = build_int1e_ao(h1e, nao);
    auto h2e_ao = build_int2e_ao(h2e, nao);

    CoeffMO  coeff_mo(nao, nmo, arma::fill::zeros);
    EnergyMO energy_mo(nmo, arma::fill::zeros);

    arma::eig_sym(energy_mo, coeff_mo, s1e_ao);

}

// double solve_rhf(int nao, int nelec_alph, int nelec_beta, double *s1e, double *h1e, double *h2e) {
//     test_rhf(nao, nelec_alph, nelec_beta, s1e, h1e, h2e);
//     return 0.0;
// }