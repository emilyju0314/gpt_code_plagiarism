bool
DataFileEngineCfg::
read(std::string& s) const
{
  char* str = rc_sprint(data_);
  if (str) {
    s = str;
    rc_free(str);
    return true;
  }
  else {
    return false;
  }
}