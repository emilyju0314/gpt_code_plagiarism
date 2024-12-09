void free_lvec( lvec  *lng_vec )
{
  free((double *) (lng_vec->elements));
  free((lvec *) (lng_vec));
  return;
}