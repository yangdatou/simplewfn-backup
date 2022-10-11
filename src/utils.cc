#include "utils.h"

void print_matrix(const arma::mat &mat, std::string title)
{
    auto ncol = mat.n_cols;
    auto nrow = mat.n_rows;

    printf("\n%s\n", title.c_str());
    for (auto icol = 0; icol < ncol; ++icol)
    {
        if (icol == 0)
        {
            printf("% 13d", icol);
        }
        else
        {
            printf("% 9d", icol);
        }
    }
    printf("\n");

    for (auto irow = 0; irow < nrow; ++irow)
    {
        printf(" -%2d ", irow);
        for (int icol = 0; icol < ncol; ++icol)
        {
            printf("% 9.3f", mat(irow, icol));
        }
        printf("\n");
    }
}

Int1eAO build_int1e_ao(double* int1e, int nao)
{
    Int1eAO int1e_ao(nao, nao, arma::fill::zeros);

    for (auto mu = 0; mu < nao; ++mu)
    {
        for (auto nu = 0; nu < nao; ++nu)
        {
            int1e_ao(mu, nu) = int1e[mu*nao + nu];
        }
    }
    return int1e_ao;
}

Int2eAO build_int2e_ao(double* int2e, int nao)
{
    auto num_pair = nao * (nao + 1) / 2;

    Int2eAO int2e_ao(num_pair, num_pair, arma::fill::zeros);

    for (auto munu = 0; munu < num_pair; ++munu)
    {
        for (auto lmsg = 0; lmsg < num_pair; ++lmsg)
        {
            int2e_ao(munu, lmsg) = int2e[munu*num_pair + lmsg];
        }
    }

    return int2e_ao;
}

double get_int1e_ao_element(const Int1eAO &int1e_ao, int mu, int nu)
{
    return int1e_ao(mu, nu);
}

double get_int2e_ao_element(const Int2eAO &int2e_ao, int mu, int nu, int lm, int sg)
{
    auto munu = mu > nu ? mu * (mu + 1) / 2 + nu : nu * (nu + 1) / 2 + mu;
    auto lmsg = lm > sg ? lm * (lm + 1) / 2 + sg : sg * (sg + 1) / 2 + lm;
    return int2e_ao(munu, lmsg);
}

// Int2eMO make_eri_mo(const Int2eAO &eri_ao, MOCoeff mo_coeff)
// {
//     int p, q, r, s;
//     int pq, rs, pqrs;

//     int mu, nu, lm, sg;
//     int munu, lmsg;

//     int nao = mo_coeff.rows();
//     int nmo = mo_coeff.cols();

//     int npair_ao = nao * (nao + 1) / 2;
//     int npair_mo = nmo * (nmo + 1) / 2;
//     int neri_mo = npair_mo * (npair_mo + 1) / 2;

//     double eri_mu_nu_lm_sg;

//     Matrix tmp(npair_mo, npair_ao);
//     Int1eAO xx_ao(nao, nao);
//     Int1eMO xx_mo(nmo, nmo);

//     tmp << Matrix::Zero(npair_mo, npair_ao);
//     xx_ao << Int1eAO::Zero(nao, nao);
//     xx_mo << Int1eMO::Zero(nmo, nmo);

//     for (mu = 0, munu = 0; mu < nao; mu++)
//     {
//         for (nu = 0; nu <= mu; nu++, munu++)
//         {

//             for (lm = 0, lmsg = 0; lm < nao; lm++)
//             {
//                 for (sg = 0; sg <= lm; sg++, lmsg++)
//                 {
//                     eri_mu_nu_lm_sg = get_eri_ao_element(eri_ao, mu, nu, lm, sg);
//                     xx_ao(lm, sg) = xx_ao(sg, lm) = eri_mu_nu_lm_sg;
//                 }
//             }

//             xx_mo = mo_coeff.transpose() * xx_ao * mo_coeff;

//             for (p = 0, pq = 0; p < nmo; p++)
//             {
//                 for (q = 0; q <= p; q++, pq++)
//                 {
//                     tmp(pq, munu) = xx_mo(p, q);
//                 }
//             }
//         }
//     }

//     Int2eMO int2e_mo(neri_mo);
//     int2e_mo << Int2eMO::Zero(neri_mo);

//     for (p = 0, pq = 0; p < nmo; p++)
//     {
//         for (q = 0; q <= p; q++, pq++)
//         {

//             for (lm = 0, lmsg = 0; lm < nao; lm++)
//             {
//                 for (sg = 0; sg <= lm; sg++, lmsg++)
//                 {
//                     xx_ao(lm, sg) = xx_ao(sg, lm) = tmp(pq, lmsg);
//                 }
//             }

//             xx_mo = mo_coeff.transpose() * xx_ao * mo_coeff;

//             for (r = 0, rs = 0; r < nmo; r++)
//             {
//                 for (s = 0; s <= r; s++, rs++)
//                 {
//                     pqrs = INDEX(pq, rs);
//                     int2e_mo(pqrs) = xx_mo(r, s);
//                 }
//             }
//         }
//     }

//     return int2e_mo;
// }
