std::string maybe_throw(const std::string& s, const float f)
{
 std::ostringstream os;
 os << s << ": " << f;

 if("throw" == s)
  throw std::runtime_error("exception thrown");

 return os.str();
}