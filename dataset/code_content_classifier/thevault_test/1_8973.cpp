int64 TravelPlusServiceTime(const Coordinates* const coords,
                            const std::vector<int64>* const service_times,
                            RoutingModel::NodeIndex from,
                            RoutingModel::NodeIndex to) {
  return ServiceTime(service_times, from) + Travel(coords, from, to);
}