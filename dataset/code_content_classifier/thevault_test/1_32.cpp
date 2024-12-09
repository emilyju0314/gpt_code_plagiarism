static void mpfr_leave(int t, floating *result) {
  t = mpfr_check_range(result->f, t, MPFR_RNDN);
  mpfr_subnormalize(result->f, t, MPFR_RNDN);
  mpfr_set_emin(default_emin);
  mpfr_set_emax(default_emax);
}