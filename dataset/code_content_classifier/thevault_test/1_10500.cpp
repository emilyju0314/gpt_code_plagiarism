bool Reconfig::DeSerialize(TFile *fp) {
  if (!fp->DeSerialize(&x_scale_)) {
    return false;
  }
  if (!fp->DeSerialize(&y_scale_)) {
    return false;
  }
  no_ = ni_ * x_scale_ * y_scale_;
  return true;
}