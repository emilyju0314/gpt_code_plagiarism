int StringRenderer::RenderAllFontsToImage(double min_coverage, const char *text, int text_length,
                                          std::string *font_used, Image *image) {
  *image = nullptr;
  // Select a suitable font to render the title with.
  const char kTitleTemplate[] = "%s : %d hits = %.2f%%, raw = %d = %.2f%%";
  std::string title_font;
  if (!FontUtils::SelectFont(kTitleTemplate, strlen(kTitleTemplate), &title_font, nullptr)) {
    tprintf("WARNING: Could not find a font to render image title with!\n");
    title_font = "Arial";
  }
  title_font += " 8";
  tlog(1, "Selected title font: %s\n", title_font.c_str());
  if (font_used) {
    font_used->clear();
  }

  std::string orig_font = font_.DescriptionName();
  if (char_map_.empty()) {
    total_chars_ = 0;
    // Fill the hash table and use that for computing which fonts to use.
    for (UNICHAR::const_iterator it = UNICHAR::begin(text, text_length);
         it != UNICHAR::end(text, text_length); ++it) {
      ++total_chars_;
      ++char_map_[*it];
    }
    tprintf("Total chars = %d\n", total_chars_);
  }
  const std::vector<std::string> &all_fonts = FontUtils::ListAvailableFonts();

  for (size_t i = font_index_; i < all_fonts.size(); ++i) {
    ++font_index_;
    int raw_score = 0;
    int ok_chars = FontUtils::FontScore(char_map_, all_fonts[i], &raw_score, nullptr);
    if (ok_chars > 0 && ok_chars >= total_chars_ * min_coverage) {
      set_font(all_fonts[i]);
      int offset = RenderToBinaryImage(text, text_length, 128, image);
      ClearBoxes(); // Get rid of them as they are garbage.
      const int kMaxTitleLength = 1024;
      char title[kMaxTitleLength];
      snprintf(title, kMaxTitleLength, kTitleTemplate, all_fonts[i].c_str(), ok_chars,
               100.0 * ok_chars / total_chars_, raw_score, 100.0 * raw_score / char_map_.size());
      tprintf("%s\n", title);
      // This is a good font! Store the offset to return once we've tried all
      // the fonts.
      if (offset) {
        last_offset_ = offset;
        if (font_used) {
          *font_used = all_fonts[i];
        }
      }
      // Add the font to the image.
      set_font(title_font);
      v_margin_ /= 8;
      Image title_image = nullptr;
      RenderToBinaryImage(title, strlen(title), 128, &title_image);
      *image |= title_image;
      title_image.destroy();

      v_margin_ *= 8;
      set_font(orig_font);
      // We return the real offset only after cycling through the list of fonts.
      return 0;
    } else {
      tprintf("Font %s failed with %d hits = %.2f%%\n", all_fonts[i].c_str(), ok_chars,
              100.0 * ok_chars / total_chars_);
    }
  }
  font_index_ = 0;
  char_map_.clear();
  return last_offset_ == 0 ? -1 : last_offset_;
}