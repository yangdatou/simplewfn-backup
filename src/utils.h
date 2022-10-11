#include <iostream>
#include <string>
#include <cassert>

#define ARMA_ALLOW_FAKE_GCC
#include <armadillo>

typedef arma::mat Int1e;
typedef arma::mat Int1eAO;
typedef arma::mat Int1eMO;

typedef arma::vec Int2e;
typedef arma::vec Int2eAO;
typedef arma::vec Int2eMO;

typedef arma::mat CoeffMO;  // MO coefficients
typedef arma::mat EnergyMO; // MO energies
typedef arma::mat DensityMatrixAO;

void print_matrix(const arma::mat& mat, std::string title);

Int1eAO build_int1e_ao(double* int1e, int nao);
Int2eAO build_int2e_ao(double* int2e, int nao);
Int2eMO build_int2e_mo(const Int2eAO& eri, const CoeffMO& mo_coeff);

double get_int1e_ao_element(const Int1eAO& int1e_ao, int mu, int nu);
double get_int2e_ao_element(const Int2eAO& int2e_ao, int mu, int nu, int lm, int sg);
double get_int2e_mo_element(const Int2eMO& int2e_mo, int p, int q, int r, int s);

