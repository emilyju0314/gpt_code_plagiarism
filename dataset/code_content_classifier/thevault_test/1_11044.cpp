double DetLineFit::EvaluateLineFit() {
  // Compute the upper quartile error from the line.
  double dist = ComputeUpperQuartileError();
  if (distances_.size() >= kMinPointsForErrorCount && dist > kMaxRealDistance * kMaxRealDistance) {
    // Use the number of mis-fitted points as the error metric, as this
    // gives a better measure of fit for badly fitted lines where more
    // than a quarter are badly fitted.
    double threshold = kMaxRealDistance * sqrt(square_length_);
    dist = NumberOfMisfittedPoints(threshold);
  }
  return dist;
}