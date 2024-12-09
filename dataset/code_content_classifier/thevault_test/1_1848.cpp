glop::GlopParameters RoutingModel::GetGlopParametersForLocalLP() const {
  glop::GlopParameters parameters;
  parameters.set_use_dual_simplex(true);
  parameters.set_use_preprocessing(false);
  if (lp_scheduling_time_limit_seconds_ > 0) {
    parameters.set_max_time_in_seconds(lp_scheduling_time_limit_seconds_);
  }
  return parameters;
}