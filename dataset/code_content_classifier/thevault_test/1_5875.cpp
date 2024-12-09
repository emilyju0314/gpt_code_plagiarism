double Config::safeLaneChangeBackDistance(const double relativeSpeed) {
  if (relativeSpeed < 0) {
    return minSafeDistance;
  }

  // just an estimate with considering acceleration
  return std::min(maxLaneChangeDistance, std::max(minLaneChangeBackDistance, relativeSpeed * minLaneChangeTime));
}