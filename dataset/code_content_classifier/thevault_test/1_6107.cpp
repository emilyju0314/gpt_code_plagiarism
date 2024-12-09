void mean_s(const int N, const int p, int J[], int **data, float T[])
{
  int TT[p_max];
  register int k, i, j;
  for ( i = 0; i < p; i++ )
    TT[i] = 0;
  for ( i = 0; i < N; i++ )
    {
      k = J[i];
      for ( j = 0; j < p; j++ )
        TT[j] += data[j][k];
     }
   for ( i = 0; i < p; i++ )
      T[i] = (float)TT[i] / (float)N;
}