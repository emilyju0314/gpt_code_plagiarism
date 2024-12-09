void dvec_copy(dvec *orig, dvec *copy)
{
  long   indx;

  for(indx = 0; indx < orig->length; indx++)
    copy->elements[indx] = orig->elements[indx];

  return;
}