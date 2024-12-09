std::string
Gogo::gc_symbol_name(Type* type)
{
  return this->type_descriptor_name(type, type->named_type()) + "..g";
}