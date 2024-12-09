VectorXd extract(const VectorXd& full, const VectorXi &ind){
  int num_indices = ind.rows();
  VectorXd target(num_indices);
  for (int i = 0; i < num_indices; i++){
    target(i) = full(ind(i));
  }
  return target;
}