bool
DataFileEngineNetcdf::
read_slice(Vector& v, const std::string& varname, int i) const
{
  int varid;
  NC_CHECK(nc_inq_varid(ncid_, varname.c_str(), &varid), varname);
  int ndims;
  NC_CHECK(nc_inq_varndims(ncid_, varid, &ndims), varname);
  if (ndims > 2) {
    CONDITIONAL_ERROR("Cannot extract slice from netcdf variable with more than 2 dimensions: "
		      + varname);
  }
  
  int dimid[2];
  NC_CHECK(nc_inq_vardimid(ncid_, varid, dimid), varname);
  size_t len[2];
  for (int idim = 0; idim < ndims; idim++) {
    NC_CHECK_UNNAMED(nc_inq_dimlen(ncid_, dimid[idim], len+idim));
  }
  //LOG << " len(0) " << len[0] << " len(1) " << len[1] << "\n";
  size_t start[3] = {0, 0};
  start[1] = i;
  len[1] = 1;

  size_t length = 1;
  length = len[0];

  Real* data = new Real[length];
#ifdef REAL_IS_FLOAT
  NC_CHECK(nc_get_vara_float(ncid_, varid, start, len, data), varname);
#else
  NC_CHECK(nc_get_vara_double(ncid_, varid, start, len, data), varname);
#endif
  Vector v_tmp(data, expression_size(length));
  v.resize(length);
  v = v_tmp;
  delete[] data;
  return true;
}