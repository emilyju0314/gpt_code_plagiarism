bool TextlineProjection::BoxOutOfHTextline(const TBOX &box, const DENORM *denorm,
                                           bool debug) const {
  int grad1 = 0;
  int grad2 = 0;
  EvaluateBoxInternal(box, denorm, debug, &grad1, &grad2, nullptr, nullptr);
  int worst_result = std::min(grad1, grad2);
  int total_result = grad1 + grad2;
  if (total_result >= 6) {
    return false; // Strongly in textline.
  }
  // Medium strength: if either gradient is negative, it is likely outside
  // the body of the textline.
  if (worst_result < 0) {
    return true;
  }
  return false;
}