void
Error_type::do_mangled_name(Gogo*, std::string* ret) const
{
  ret->append("{error}");
}