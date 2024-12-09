int64 Travel(const Coordinates* const coords, RoutingModel::NodeIndex from,
             RoutingModel::NodeIndex to) {
  DCHECK(coords != nullptr);
  const int xd = coords->at(from.value()).first - coords->at(to.value()).first;
  const int yd =
      coords->at(from.value()).second - coords->at(to.value()).second;
  return static_cast<int64>(kScalingFactor * sqrt(1.0L * xd * xd + yd * yd));
}