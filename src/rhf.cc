#include <iostream>
#include <string>
#include <cassert>

const double TOL = 1e-8;
const int MAX_ITER = 100;

void test_rhf(int nao, int nelec_alph, int nelec_beta, double *s1e, double *h1e, double *h2e) {
    std::cout << "nao = " << nao << std::endl;
    std::cout << "nelec_alph = " << nelec_alph << std::endl;
    std::cout << "nelec_beta = " << nelec_beta << std::endl;
}