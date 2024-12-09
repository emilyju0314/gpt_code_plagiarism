void dvec_scale(double scal, dvec *vec)
{
  long   indx;

  for(indx = 0; indx < vec->length; indx++)
    vec->elements[indx] *= scal;

  return;
}