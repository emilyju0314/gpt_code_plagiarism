vcard::vcard::values_t vcard::vcard::names() const
{
  values_t result;
  const std::list<std::string> name_keys = { "FN", "N", "NICKNAME" };
  for (auto ifield = _fields.begin(); ifield != _fields.end(); ifield++) {
    for (auto key : name_keys) {
      if (is_key(ifield->first, key)) {
        std::string name = format_name(ifield->second, find_no_case(ifield->first, "ENCODING=QUOTED-PRINTABLE"));
        result.push_back(name);
      }
    }
  }
  return result;
}