IntVector 
DataFileEngineCfg::size(const std::string& varname) const
{
  IntVector out;
  int m, n, len;
  len = rc_size(data_, varname.c_str(), &m, &n);
  if (m == 0 && n == 0) {
    if (len > 0) {
      out.resize(1);
      out = len;
    } // Else out will be empty indicating varname does not exist or
      // is empty
  }
  else {
    if (m > 0 && n > 0) {
      out.resize(2);
      out(0) = m;
      out(1) = n;
      if (len != m*n) {
	WARNING << "Matrix \"" << varname << "\" in cfg file \"" << filename_
		<< "\" has length inconsistent with dimensions ("
		<< len << " != " << m << " * " << n << ")";
	WARNING << rc_sprint(data_);
	ENDWARNING;
      }
    }
    else {
      out.resize(1);
      out = len;
      if (len != m+n) {
	WARNING << "Stated length of vector in cfg file is not correct ("
		<< len << " != " << m+n << ")";
	ENDWARNING;
      }
    }
  }
  return out; 
}