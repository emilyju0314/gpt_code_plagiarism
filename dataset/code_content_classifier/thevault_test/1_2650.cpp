bool
DataFileEngineNetcdf::
read(std::string& s) const
{
  CONDITIONAL_ERROR("Cannot read the entire contents of a NetCDF file into a string");
  return false;
}