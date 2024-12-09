bool
DataFileEngineNetcdf::
copy_attributes(const std::string& varname,
		OutputDataFile* output, const std::string& output_varname) const
{
  ERROR << "DataFileEngineNetcdf::copy_attributes not yet implemented for NetCDF files";
  THROW(UNEXPECTED_EXCEPTION);
}