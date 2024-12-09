double media(double v[], int n){
  double m = 0.0;
  for (int i = 0; i < n; i++) //calculo da media
      m += v[i];
  m /= n;
  return m;
}