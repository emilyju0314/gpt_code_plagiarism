double dvec_norm2(dvec *vec)
{
  long   indx;
  double norm;
  
  norm = 0.0;

  for(indx = 0; indx < vec->length; indx++)
    norm += sqr(vec->elements[indx]);

  return sqrt(norm);
}