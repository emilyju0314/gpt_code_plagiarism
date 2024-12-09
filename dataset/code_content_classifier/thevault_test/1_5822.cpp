int ij2rUpTr(int Nel, int i, int j)
{
  if ((i>j)||(i<0)||(j<0)) return(0);
  else
    return(i*Nel-i*(i-1)/2+(j-i));
}