UNICHAR_ID WERD_RES::BothHyphens(UNICHAR_ID id1, UNICHAR_ID id2) {
  const char *ch = uch_set->id_to_unichar(id1);
  const char *next_ch = uch_set->id_to_unichar(id2);
  if (strlen(ch) == 1 && strlen(next_ch) == 1 && (*ch == '-' || *ch == '~') &&
      (*next_ch == '-' || *next_ch == '~')) {
    return uch_set->unichar_to_id("-");
  }
  return INVALID_UNICHAR_ID;
}