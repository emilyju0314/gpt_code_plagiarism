std::string
Gogo::interface_method_table_name(Interface_type* itype, Type* type,
				  bool is_pointer)
{
  return ((is_pointer ? "pimt.." : "imt..")
	  + itype->mangled_name(this)
	  + ".."
	  + type->mangled_name(this));
}