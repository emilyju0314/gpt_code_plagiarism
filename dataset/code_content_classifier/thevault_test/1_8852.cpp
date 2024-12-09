double mean(double *vals, int n_vals){
  
  double m=0;
  for(int i=0; i<n_vals; i++){
    m+=vals[i];
  }

  return m/double(n_vals);
}