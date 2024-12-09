std::string VerboseOutput(const RoutingModel& routing, const Assignment& assignment,
                     const Coordinates& coords,
                     const std::vector<int64>& service_times) {
  std::string output;
  const RoutingDimension& time_dimension = routing.GetDimensionOrDie("time");
  const RoutingDimension& load_dimension = routing.GetDimensionOrDie("demand");
  for (int i = 0; i < routing.vehicles(); ++i) {
    StringAppendF(&output, "Vehicle %d: ", i);
    int64 index = routing.Start(i);
    if (routing.IsEnd(assignment.Value(routing.NextVar(index)))) {
      output.append("empty");
    } else {
      while (!routing.IsEnd(index)) {
        RoutingModel::NodeIndex real_node = routing.IndexToNode(index);
        StringAppendF(&output, "%d ", real_node.value());
        const IntVar* vehicle = routing.VehicleVar(index);
        StringAppendF(&output, "Vehicle(%lld) ", assignment.Value(vehicle));
        const IntVar* arrival = time_dimension.CumulVar(index);
        StringAppendF(&output, "Time(%lld..%lld) ", assignment.Min(arrival),
                      assignment.Max(arrival));
        const IntVar* load = load_dimension.CumulVar(index);
        StringAppendF(&output, "Load(%lld..%lld) ", assignment.Min(load),
                      assignment.Max(load));
        index = assignment.Value(routing.NextVar(index));
        StringAppendF(&output, "Transit(%lld) ",
                      TravelPlusServiceTime(&coords, &service_times, real_node,
                                            routing.IndexToNode(index)));
      }
      output.append("Route end ");
      const IntVar* vehicle = routing.VehicleVar(index);
      StringAppendF(&output, "Vehicle(%lld) ", assignment.Value(vehicle));
      const IntVar* arrival = time_dimension.CumulVar(index);
      StringAppendF(&output, "Time(%lld..%lld) ", assignment.Min(arrival),
                    assignment.Max(arrival));
      const IntVar* load = load_dimension.CumulVar(index);
      StringAppendF(&output, "Load(%lld..%lld) ", assignment.Min(load),
                    assignment.Max(load));
    }
    output.append("\n");
  }
  return output;
}