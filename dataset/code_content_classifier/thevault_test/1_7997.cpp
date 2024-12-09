std::string
xclbin::symbol::arg::
get_string_value(const unsigned char* data) const
{
  std::stringstream sstr;
  if ( (type == "float") || (type == "double") ) {
    //Handle float/double by casting
    if (hostsize == 64)
      sstr << *(reinterpret_cast<const double*> (data));
    else
      sstr << *(reinterpret_cast<const float*> (data));
  }
  else {
    //Integral type: char,short,int,long and their unsigned versions
    //Handle all integral types here
    sstr << "0x";
    for (int i = hostsize-1; i >= 0; --i) {
      //data[i] has to be sent in as an integer to the ostream,
      //if not data[i] gets interpreted as character (ie. non-ascii characters in output)
      sstr << std::hex << std::setw(2) << std::setfill('0') << (unsigned int)data[i];
    }
  }
  return sstr.str();
}