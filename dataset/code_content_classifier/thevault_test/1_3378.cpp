bool TensorIsfinite(const framework::Tensor& tensor) {
  ContainsInfPredicate pred_inf;
  ContainsNANPredicate pred_nan;
  return !Any(tensor, pred_inf) && !Any(tensor, pred_nan);
}