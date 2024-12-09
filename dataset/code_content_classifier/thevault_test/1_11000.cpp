UNICHAR_ID WERD_RES::BothQuotes(UNICHAR_ID id1, UNICHAR_ID id2) {
  const char *ch = uch_set->id_to_unichar(id1);
  const char *next_ch = uch_set->id_to_unichar(id2);
  if (is_simple_quote(ch, strlen(ch)) &&
      is_simple_quote(next_ch, strlen(next_ch))) {
    return uch_set->unichar_to_id("\"");
  }
  return INVALID_UNICHAR_ID;
}