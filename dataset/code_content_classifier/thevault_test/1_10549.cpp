void ShapeClassifier::UnicharPrintResults(const char *context,
                                          const std::vector<UnicharRating> &results) const {
  tprintf("%s\n", context);
  for (const auto &result : results) {
    tprintf("%g: c_id=%d=%s", result.rating, result.unichar_id,
            GetUnicharset().id_to_unichar(result.unichar_id));
    if (!result.fonts.empty()) {
      tprintf(" Font Vector:");
      for (auto font : result.fonts) {
        tprintf(" %d", font.fontinfo_id);
      }
    }
    tprintf("\n");
  }
}