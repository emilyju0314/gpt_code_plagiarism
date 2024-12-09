void GeoVaLs::getAtLevel(std::vector<int> & vals, const std::string & var, const int lev) const {
  oops::Log::trace() << "GeoVaLs::getAtLevel(int) starting" << std::endl;
  std::vector<double> doublevals(vals.size());
  this->getAtLevel(doublevals, var, lev);
  vals.assign(doublevals.begin(), doublevals.end());
  oops::Log::trace() << "GeoVaLs::getAtLevel(int) done" << std::endl;
}