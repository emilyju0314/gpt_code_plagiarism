void GeoVaLs::getAtLocation(std::vector<int> & vals,
                            const std::string & var,
                            const int loc) const {
  oops::Log::trace() << "GeoVaLs::getAtLocation(int) starting" << std::endl;
  std::vector <double> doublevals(vals.size());
  this->getAtLocation(doublevals, var, loc);
  vals.assign(doublevals.begin(), doublevals.end());
  oops::Log::trace() << "GeoVaLs::getAtLocation(int) done" << std::endl;
}