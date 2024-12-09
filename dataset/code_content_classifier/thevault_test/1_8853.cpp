void meanvar(double *vals, int n_vals, double *res){
  double m2=0, m=0, val;
  for(int i=0; i<n_vals; i++){
    val=vals[i];
    m+=val;
    m2+=val*val;
  }

  m  /= double(n_vals);
  m2 /= double(n_vals);

  res[0] = m;
  res[1] = m2-(m*m);

}