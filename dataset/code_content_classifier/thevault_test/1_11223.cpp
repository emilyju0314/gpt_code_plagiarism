void UNICHARSET::AppendOtherUnicharset(const UNICHARSET &src) {
  int initial_used = unichars.size();
  for (unsigned ch = 0; ch < src.unichars.size(); ++ch) {
    const UNICHAR_PROPERTIES &src_props = src.unichars[ch].properties;
    const char *utf8 = src.id_to_unichar(ch);
    int id = unichars.size();
    if (contains_unichar(utf8)) {
      id = unichar_to_id(utf8);
      // Just expand current ranges.
      unichars[id].properties.ExpandRangesFrom(src_props);
    } else {
      unichar_insert_backwards_compatible(utf8);
      unichars[id].properties.SetRangesEmpty();
    }
  }
  // Set properties, including mirror and other_case, WITHOUT reordering
  // the unicharset.
  PartialSetPropertiesFromOther(initial_used, src);
}