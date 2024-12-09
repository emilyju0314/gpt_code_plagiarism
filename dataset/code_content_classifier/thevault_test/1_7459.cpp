void local_conv(const float u[], float w[], const int n,
                const float mu = .5, const float sigma = .001) {
  float *v = new float[n], x, isigma = 1./sigma;
  for (int i=0;i<n;++i) {
    x = (float)i/(float)n;
    v[i] = exp(-(x-mu)*(x-mu)*isigma);
  }

/* this works
  float *ww = new float[2*n-1];
  for (int k=0;k<2*n-1;++k) {
    ww[k] = 0;
    for (int j=max(0,k-n);j<min(k,n);++j)
      ww[k] += u[j]*v[k-j];
  }
*/

  /* this is with periodic bc's */
  int lj;
  for (int k=n/2;k<n+n/2;++k) {
    w[k-n/2] = 0;
    for (int j=0;j<n;++j) {
      lj = (k-j)%n; if (lj<0) lj += n;
      w[k-n/2] += u[j]*v[lj];
    }
  }

  delete[] v;
}