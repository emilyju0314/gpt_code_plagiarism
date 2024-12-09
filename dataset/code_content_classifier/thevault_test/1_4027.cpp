vcard::vcard::values_t vcard::vcard::uids() const
{
  values_t result;
  for (auto ifield = _fields.begin(); ifield != _fields.end(); ifield++) {
    if (is_key(ifield->first, "UID")) result.push_back(ifield->second);
  }
  return result;
}