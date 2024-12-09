void UNICHARSET::CopyFrom(const UNICHARSET &src) {
  clear();
  for (unsigned ch = 0; ch < src.unichars.size(); ++ch) {
    const UNICHAR_PROPERTIES &src_props = src.unichars[ch].properties;
    const char *utf8 = src.id_to_unichar(ch);
    unichar_insert_backwards_compatible(utf8);
    unichars[ch].properties.ExpandRangesFrom(src_props);
  }
  // Set properties, including mirror and other_case, WITHOUT reordering
  // the unicharset.
  PartialSetPropertiesFromOther(0, src);
}