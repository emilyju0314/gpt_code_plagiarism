double objective(const std::vector<double> &x, std::vector<double>& grad, void* data)
{
    // For counting the number of function evaluations
    ++ count;

    const MatrixXd& X = static_cast<const Data*>(data)->X;
    const VectorXd& y = static_cast<const Data*>(data)->y;

    const unsigned N = X.cols();

    const double   a = x[0];
#ifdef NOISELESS
    const double   b = b_fixed;
#else
    const double   b = x[1];
#endif
    const VectorXd r = [&x]() { std::vector<double> _x = x; return Eigen::Map<VectorXd>(&_x[2], _x.size() - 2); }();

    const MatrixXd C     = Regressor::calc_C(X, a, b, r);
    const MatrixXd C_inv = C.inverse();

    // When the algorithm is gradient-based, compute the gradient vector
    if (grad.size() == x.size())
    {
        const VectorXd g = calc_grad(X, C_inv, y, a, b, r);
        for (unsigned i = 0; i < g.rows(); ++ i) grad[i] = g(i);
    }

    const double term1 = - 0.5 * y.transpose() * C_inv * y;
    const double term2 = - 0.5 * std::log(C.determinant());
    const double term3 = - 0.5 * N * std::log(2.0 * M_PI);

    // Computing the regularization terms from a prior assumptions
    const double a_prior = calc_a_prior(a);
#ifdef NOISELESS
    const double b_prior = 1.0;
#else
    const double b_prior = calc_b_prior(b);
#endif
    const double r_prior = [&r]()
    {
        double sum = 0.0;
        for (unsigned i = 0; i < r.rows(); ++ i) sum += calc_r_i_prior(r, i);
        return sum;
    }();
    const double regularization = useLogNormalPrior ? (a_prior + b_prior + r_prior) : 0.0;

    return term1 + term2 + term3 + regularization;
}