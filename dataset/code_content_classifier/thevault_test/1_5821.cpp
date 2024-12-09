int Pmn(int Nel, int i, int j)
{

  int Pmm=0;
  int add=0;

  if (i>=j) //n=i,m=j
    {
      Pmm=(2*Nel-j)*j;
      add=2*(i-j);
    }
  else // n=j,m=i
    {
      Pmm=(2*Nel-i)*i;
      add=2*(j-i)-1;
    }

  return(Pmm+add);
}