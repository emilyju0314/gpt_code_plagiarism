DataFileEngineNetcdf::
DataFileEngineNetcdf(const std::string& filename, bool throw_exceptions)
  : throw_exceptions_(throw_exceptions)
{
  int  numgrps;
  NC_CHECK(nc_open(filename.c_str(), 0, &root_ncid_), filename);
  DETAIL << "Opened " << filename << "\n";
  filename_ = filename;

#ifdef NC_NETCDF4
  // Get a list of ncids for the root group (that is, find out if
  // there are any groups already defined)
  NC_CHECK(nc_inq_grps(root_ncid_, &numgrps, NULL),filename);
  if (numgrps != 0) {
    // We have groups: look for one called "ScienceData"
    size_t len;
    intVector ncids(numgrps);
    NC_CHECK(nc_inq_grps(root_ncid_, NULL, ncids.data_pointer()),filename);
    // Loop over the group ids and store the group names
    char name_in[15];
    for (int i = 1; i < numgrps; i++){
      NC_CHECK(nc_inq_grpname_full(ncids(i), &len, name_in),filename);
      if (strcmp ("/ScienceData",name_in) == 0) {
	// Found: set the ncid that will be used by subsequent calls
	// to find variables
	ncid_ = ncids(i);
	break;
      }
      else {
	ERROR << "Error reading " << filename 
	      << " no \"ScienceData\" group";
	THROW(PRODUCT_FORMAT_ERROR);
      }
    }
  }
  else {
    // No groups found
    ncid_ = root_ncid_;
  }
#else
  // NetCDF3: don't look for groups
  ncid_ = root_ncid_;
#endif


}