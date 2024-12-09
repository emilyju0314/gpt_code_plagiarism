std::vector<std::vector<double>> CSK_Interface::interpolate_nu_ratio(const double etemp,
                                                                     const bool limit_grps) const {

  // Be sure the passed electron temperature is within the bounds of the lib!
  Require(etemp >= ei->get_min_etemp());
  Require(etemp <= ei->get_max_etemp());

  // call the appropriate routine in the electron interp object
  return ei->interpolate_nu_ratio(etemp, limit_grps);
}