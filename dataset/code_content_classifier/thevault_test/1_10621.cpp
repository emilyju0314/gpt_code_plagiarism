void Tesseract::SetupUniversalFontIds() {
  // Note that we can get away with bitwise copying FontInfo in
  // all_fonts, as it is a temporary structure and we avoid setting the
  // delete callback.
  UnicityTable<FontInfo> all_fonts;

  // Create the universal ID table.
  CollectFonts(get_fontinfo_table(), &all_fonts);
  for (auto &sub_lang : sub_langs_) {
    CollectFonts(sub_lang->get_fontinfo_table(), &all_fonts);
  }
  // Assign ids from the table to each font table.
  AssignIds(all_fonts, &get_fontinfo_table());
  for (auto &sub_lang : sub_langs_) {
    AssignIds(all_fonts, &sub_lang->get_fontinfo_table());
  }
  font_table_size_ = all_fonts.size();
}