bool
Gogo::is_special_name(const std::string& name)
{
  return (name.find("..hash") != std::string::npos
	  || name.find("..eq") != std::string::npos
	  || name.find("..stub") != std::string::npos
	  || name.find("..func") != std::string::npos
	  || name.find("..r") != std::string::npos
	  || name.find("..init") != std::string::npos
	  || name.find("..thunk") != std::string::npos
	  || name.find("..import") != std::string::npos);
}