dvec *alloc_dvec( long  dvec_size )
{
  dvec *dbl_vec;

  dbl_vec = (dvec *) malloc( sizeof(dvec) );
  if (!dbl_vec) lsqr_error("lsqr: vector allocation failure in function alloc_dvec()", -1);

  dbl_vec->elements = (double *) malloc( (dvec_size) * sizeof(double) );
  if (!dbl_vec->elements) lsqr_error("lsqr: element allocation failure in function alloc_dvec()", -1);

  dbl_vec->length = dvec_size;

  return dbl_vec;
}