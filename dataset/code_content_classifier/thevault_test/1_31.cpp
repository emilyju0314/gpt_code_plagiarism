static void mpfr_enter(mpfr_prec_t p, mpfr_exp_t e, floating *result) {
  mpfr_init2(result->f, p);
  result->exp = e;
  default_emax = mpfr_get_emax();
  default_emin = mpfr_get_emin();
  mpfr_set_emin(emin(e, p) - p + 2);
  mpfr_set_emax(emax(e) + 1);
}