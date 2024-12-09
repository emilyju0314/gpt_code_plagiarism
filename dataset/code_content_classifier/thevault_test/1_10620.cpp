static void AssignIds(const UnicityTable<FontInfo> &all_fonts, UnicityTable<FontInfo> *lang_fonts) {
  for (int i = 0; i < lang_fonts->size(); ++i) {
    auto index = all_fonts.get_index(lang_fonts->at(i));
    lang_fonts->at(i).universal_id = index;
  }
}