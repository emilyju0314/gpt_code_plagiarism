static void CollectFonts(const UnicityTable<FontInfo> &new_fonts,
                         UnicityTable<FontInfo> *all_fonts) {
  for (int i = 0; i < new_fonts.size(); ++i) {
    // UnicityTable uniques as we go.
    all_fonts->push_back(new_fonts.at(i));
  }
}