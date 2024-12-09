double desvpad(double v[], int n, double med){
  double dv = 0.0;
  for (int i = 0; i < n; i++)
      dv += (v[i]-med)*(v[i]-med); //calculo do desvio padrao
  dv = sqrt(dv/n);
  return dv;
}