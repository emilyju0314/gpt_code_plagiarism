void reverse_map(Octet *inv_map, Octet *my_map, int *n_rects, Octet *valid_class, float T[][p_max])
{
  float sec_T[Max_rects][p_max];
  register int u=0, k, j;
  for(j=0;j<*n_rects;j++)
    {
      if(valid_class[j])
	{
          for(k=0;k<3;k++)
            sec_T[u][k]=T[j][k];
          my_map[j]=u;
          inv_map[u]=j;
          u++;
        }
    }
  my_map[*n_rects]=u;
  inv_map[u]=*n_rects;
  *n_rects=u;
  for(j=0;j<*n_rects;j++)
    for(k=0;k<3;k++) 
      T[j][k]=sec_T[j][k];
}