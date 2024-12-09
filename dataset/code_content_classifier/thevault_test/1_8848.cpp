double  GaussHermiteIntegration(int n)
{
  double *x = new double [n];
  double *w = new double [n];
  GaussHermiteQuadrature(x, w, n);
  double Integral = 0.0;
  int i, j, k, l;
  # pragma omp parallel default(shared) private (i, j, k, l) reduction(+:Integral)
  {
    # pragma omp for
    for (i = 0;  i < n; i++){
      for (j = 0;  j < n; j++){
	for (k = 0;  k < n; k++){
	  for (l = 0;  l < n; l++){
	    Integral += w[i]*w[j]*w[k]*w[l]*Integrand(x[i],x[j],x[k],x[l]);
	  }
	}
      }
    }
  } // end parallel region
  delete [] x;
  delete [] w;
  return Integral;
}