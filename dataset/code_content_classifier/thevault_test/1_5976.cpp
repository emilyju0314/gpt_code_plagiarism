void free_dvec( dvec  *dbl_vec )
{
  free((double *) (dbl_vec->elements));
  free((dvec *) (dbl_vec));
  return;
}