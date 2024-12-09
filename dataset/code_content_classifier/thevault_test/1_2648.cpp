IntVector 
DataFileEngineNetcdf::size(const std::string& varname) const
{
  IntVector out;
  int varid;
  if (nc_inq_varid(ncid_, varname.c_str(), &varid) != NC_NOERR) {
    // Variable not found
    return out;
  }
  int ndims;
  NC_CHECK(nc_inq_varndims(ncid_, varid, &ndims), varname);
  if (ndims == 0) {
    // Scalar
    out.resize(1);
    out = 1;
    return out;
  }
  
  // First fill "out" with the dimention IDs
  out.resize(ndims);
  NC_CHECK(nc_inq_vardimid(ncid_, varid, out.data_pointer()), varname);
  for (int idim = 0; idim < ndims; idim++) {
    // Replace the dimension ID with its length
    size_t len;
    NC_CHECK(nc_inq_dimlen(ncid_, out(idim), &len), varname);
    out(idim) = len;
  }
  return out;
}