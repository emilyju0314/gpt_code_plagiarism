static
std::string
translate_varname(const std::string& varname)
{
  std::string new_varname;
  if (varname.find_first_of(".") == std::string::npos) {
    new_varname = "main/" + varname;
  } 
  else {
    int n_nested = 0;
    new_varname = varname;
    for (size_t i = 0; i < new_varname.size(); ++i) {
      if (new_varname[i] == '.') {
	new_varname[i] = '/';
	++n_nested;
	if (n_nested > 1) {
	  break;
	}
      }
    }
  }
  //  LOG << "Name conversion: \"" << varname << "\" to \"" << new_varname << "\"\n";
  return new_varname;  
}