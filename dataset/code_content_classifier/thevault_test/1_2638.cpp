bool
DataFileEngineXml::
read(bool& x, const std::string& varname, int j, int i) const
{
  int my_x;
  bool status = read(my_x, varname, j, i);
  if (status) {
    if (my_x) {
      x = true;
    }
    else {
      x = false;
    }
  }
  return status;
}