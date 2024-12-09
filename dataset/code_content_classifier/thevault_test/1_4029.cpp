vcard::vcard::values_t vcard::vcard::tels() const
{
  values_t result;
  for (auto ifield = _fields.begin(); ifield != _fields.end(); ifield++) {
    if (is_key(ifield->first, "TEL")) result.push_back(format_tel(ifield->second));
  }
  return result;
}