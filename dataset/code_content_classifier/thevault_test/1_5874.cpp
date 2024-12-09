double Config::safeLaneChangeFrontDistance(const double relativeSpeed) {
  if (relativeSpeed < 0) {
    return minSafeDistance;
  }

  // just an estimate with considering acceleration
  return std::min(maxLaneChangeDistance, std::max(minLaneChangeFrontDistance, relativeSpeed * minLaneChangeTime));
}