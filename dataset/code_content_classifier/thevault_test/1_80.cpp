void GeoVaLs::getAtLocation(std::vector<float> & vals,
                            const std::string & var,
                            const int loc) const {
  oops::Log::trace() << "GeoVaLs::getAtLocation(float) starting" << std::endl;
  std::vector <double> doublevals(vals.size());
  this->getAtLocation(doublevals, var, loc);
  vals.assign(doublevals.begin(), doublevals.end());
  oops::Log::trace() << "GeoVaLs::getAtLocation(float) done" << std::endl;
}