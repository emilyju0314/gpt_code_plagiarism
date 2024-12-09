double logsumexp(NumericMatrix &mat) {
  double maximum = mat(0, 0);
  double sum = 0.0;
  // for (size_t i = 0; i < mat.nrow(); i++) {
  //   for (size_t j = 0; j < mat.ncol(); j++) {
  for (size_t j = 0; j < mat.ncol(); j++) {
    for (size_t i = 0; i < mat.nrow(); i++) {
      if (mat(i, j) > maximum) {
        maximum = mat(i, j);
      }
    }
  }
  if (maximum < -1000000000) {
    return (maximum);
  }
  for (size_t j = 0; j < mat.ncol(); j++) {
    for (size_t i = 0; i < mat.nrow(); i++) {
      sum += exp(mat(i, j) - maximum);
    }
  }

  return (log(sum) + maximum);
}