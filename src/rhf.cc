#include <iostream>
#include <string>
#include <cassert>

#include <armadillo>

const double TOL = 1e-8;
const int MAX_ITER = 100;

extern "C" void test_rhf(int nao, int nelec_alph, int nelec_beta, double *s1e, double *h1e, double *h2e) {
    std::cout << "Armadillo version: " << arma::arma_version::as_string() << std::endl;
    std::cout << "nao = " << nao << std::endl;
    std::cout << "nelec_alph = " << nelec_alph << std::endl;
    std::cout << "nelec_beta = " << nelec_beta << std::endl;

    arma::mat ovlp(s1e, nao, nao, false);
    arma::mat hcore(h1e, nao, nao, false);

    ovlp.print("ovlp");
    hcore.print("hcore");
}

// double solve_rhf(int nao, int nelec_alph, int nelec_beta, double *s1e, double *h1e, double *h2e) {
//     test_rhf(nao, nelec_alph, nelec_beta, s1e, h1e, h2e);
//     return 0.0;
// }