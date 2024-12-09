int TextlineProjection::EvaluateBoxInternal(const TBOX &box, const DENORM *denorm, bool debug,
                                            int *hgrad1, int *hgrad2, int *vgrad1,
                                            int *vgrad2) const {
  int top_gradient = BestMeanGradientInRow(denorm, box.left(), box.right(), box.top(), true);
  int bottom_gradient =
      -BestMeanGradientInRow(denorm, box.left(), box.right(), box.bottom(), false);
  int left_gradient = BestMeanGradientInColumn(denorm, box.left(), box.bottom(), box.top(), true);
  int right_gradient =
      -BestMeanGradientInColumn(denorm, box.right(), box.bottom(), box.top(), false);
  int top_clipped = std::max(top_gradient, 0);
  int bottom_clipped = std::max(bottom_gradient, 0);
  int left_clipped = std::max(left_gradient, 0);
  int right_clipped = std::max(right_gradient, 0);
  if (debug) {
    tprintf("Gradients: top = %d, bottom = %d, left= %d, right= %d for box:", top_gradient,
            bottom_gradient, left_gradient, right_gradient);
    box.print();
  }
  int result = std::max(top_clipped, bottom_clipped) - std::max(left_clipped, right_clipped);
  if (hgrad1 != nullptr && hgrad2 != nullptr) {
    *hgrad1 = top_gradient;
    *hgrad2 = bottom_gradient;
  }
  if (vgrad1 != nullptr && vgrad2 != nullptr) {
    *vgrad1 = left_gradient;
    *vgrad2 = right_gradient;
  }
  return result;
}