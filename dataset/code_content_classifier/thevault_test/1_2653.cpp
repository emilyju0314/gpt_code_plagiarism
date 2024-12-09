bool
DataFileEngineNetcdf::read_missing_value(Real& missing_val, const std::string& varname) const
{
  int varid;
  if (nc_inq_varid(ncid_, varname.c_str(), &varid) == NC_NOERR) {
    const char* missing_value = "missing_value";
    for (int i = 0; i < 2; i++) {
      size_t n = 0;
      if (nc_inq_attlen(ncid_, varid, missing_value, &n) == NC_NOERR) {
	if (n > 1) {
	  CONDITIONAL_ERROR("Attempt to read missing_value as one real element from multi-element netcdf attribute: "
			    + varname);
	}
#ifdef REAL_IS_FLOAT
	NC_CHECK(nc_get_att_float(ncid_, varid, missing_value, &missing_val), varname);
	return true;
#else
	NC_CHECK(nc_get_att_double(ncid_, varid, missing_value, &missing_val), varname);
	return true;
#endif
	
      }
      missing_value = "_FillValue";
    }
  }
  return false;
}