double Config::safeDistance(const double relativeSpeed) {
  if (relativeSpeed < 0) {
    return minSafeDistance;
  }

  return std::min(maxDistance, std::max(minSafeDistance, relativeSpeed - 0.5 * Config::maxAcceleration));
}