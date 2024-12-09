void UNICHARSET::ExpandRangesFromOther(const UNICHARSET &src) {
  for (unsigned ch = 0; ch < unichars.size(); ++ch) {
    const char *utf8 = id_to_unichar(ch);
    UNICHAR_PROPERTIES properties;
    if (src.GetStrProperties(utf8, &properties)) {
      // Expand just the ranges from properties.
      unichars[ch].properties.ExpandRangesFrom(properties);
    }
  }
}