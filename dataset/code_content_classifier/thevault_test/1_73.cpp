void GeoVaLs::get(std::vector<float> & vals, const std::string & var) const {
  oops::Log::trace() << "GeoVaLs::get 2D starting" << std::endl;
  /// Call method to get double values (Fortran data structure stores data in double)
  /// and convert to floats
  std::vector<double> doublevals(vals.size());
  this->get(doublevals, var);
  vals.assign(doublevals.begin(), doublevals.end());
  oops::Log::trace() << "GeoVaLs::get 2D done" << std::endl;
}