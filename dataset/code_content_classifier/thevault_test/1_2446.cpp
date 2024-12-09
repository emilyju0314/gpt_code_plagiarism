Sobol_Sequence::Sobol_Sequence(unsigned const dimension)
    : gsl_(gsl_qrng_alloc(gsl_qrng_sobol, dimension)), values_(dimension) {
  Require(dimension > 0);
  shift();
  Ensure(check_class_invariants());
}