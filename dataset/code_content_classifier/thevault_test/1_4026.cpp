void vcard::vcard::insert(const key_t& key, const value_t& value)
{
  auto same_key = _fields.equal_range(key);
  for (auto isame_key = same_key.first; isame_key != same_key.second; isame_key++) {
    if (value < isame_key->second) {
      _fields.emplace_hint(isame_key, key, value);
      return;
    }
  }
  _fields.emplace(key, value);
}