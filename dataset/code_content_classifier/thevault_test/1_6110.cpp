void covariance_w(const int N, int M, const int p,  int **data, 
               int *w, float T[], float C[p_max][p_max])
{
  register int i, j, k, l;
  int TT[p_max];
  for ( i = 0; i < p; i++ )
    TT[i] = 0;
  for ( i = 0; i < M; i++ )
    for ( j = 0; j < p; j++ )
      TT[j] += w[i]*data[j][i]; 
  for ( i = 0; i < p; i++ )
      T[i] = (float) TT[i] / (float)N;

  for ( i = 0; i < p; i++ )
    for ( j = i; j < p; j++ )
      C[i][j] = 0.0;
  for ( i = 0; i < M; i++ )
    {
      for ( k = 0; k < p; k++ )
	for ( l = k; l < p; l++ )
	   C[k][l]+=w[i]*(data[k][i]-T[k])*(data[l][i]-T[l]);
    }
  for ( k = 0; k < p; k++ )
    {
    for ( l = k; l < p; l++ )
      C[k][l] /= (float)(N-1);
    for ( l = 0; l < k; l++ )
      C[k][l] = C[l][k];
    }
}