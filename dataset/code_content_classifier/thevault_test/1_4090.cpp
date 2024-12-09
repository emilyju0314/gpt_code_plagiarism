double eval_gaussian(Vec3b &X, Vec3b &u, double sig_squared){
    double s = norm_sq(X-u);
    double gaus = exp(-0.5 * s / sig_squared);
    gaus = gaus/pow(2.0 * PI * sig_squared, 1.5);
    return gaus;
}