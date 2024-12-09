void UNICHARSET::PartialSetPropertiesFromOther(int start_index,
                                               const UNICHARSET &src) {
  for (unsigned ch = start_index; ch < unichars.size(); ++ch) {
    const char *utf8 = id_to_unichar(ch);
    UNICHAR_PROPERTIES properties;
    if (src.GetStrProperties(utf8, &properties)) {
      // Setup the script_id, other_case, and mirror properly.
      const char *script = src.get_script_from_script_id(properties.script_id);
      properties.script_id = add_script(script);
      const char *other_case = src.id_to_unichar(properties.other_case);
      if (contains_unichar(other_case)) {
        properties.other_case = unichar_to_id(other_case);
      } else {
        properties.other_case = ch;
      }
      const char *mirror_str = src.id_to_unichar(properties.mirror);
      if (contains_unichar(mirror_str)) {
        properties.mirror = unichar_to_id(mirror_str);
      } else {
        properties.mirror = ch;
      }
      unichars[ch].properties.CopyFrom(properties);
      set_normed_ids(ch);
    }
  }
}