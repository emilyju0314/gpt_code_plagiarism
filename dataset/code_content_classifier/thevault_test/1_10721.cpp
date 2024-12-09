static void AddAllScriptsConverted(const UNICHARSET &sid_set, const UNICHARSET &osd_set,
                                   std::vector<int> *allowed_ids) {
  for (int i = 0; i < sid_set.get_script_table_size(); ++i) {
    if (i != sid_set.null_sid()) {
      const char *script = sid_set.get_script_from_script_id(i);
      allowed_ids->push_back(osd_set.get_script_id_from_name(script));
    }
  }
}