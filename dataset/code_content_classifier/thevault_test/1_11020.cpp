const char *LTRResultIterator::WordFontAttributes(bool *is_bold, bool *is_italic,
                                                  bool *is_underlined, bool *is_monospace,
                                                  bool *is_serif, bool *is_smallcaps,
                                                  int *pointsize, int *font_id) const {
  const char *result = nullptr;

  if (it_->word() == nullptr) {
    // Already at the end!
    *pointsize = 0;
  } else {
    float row_height =
        it_->row()->row->x_height() + it_->row()->row->ascenders() - it_->row()->row->descenders();
    // Convert from pixels to printers points.
    *pointsize =
        scaled_yres_ > 0 ? static_cast<int>(row_height * kPointsPerInch / scaled_yres_ + 0.5) : 0;

#ifndef DISABLED_LEGACY_ENGINE
    const FontInfo *font_info = it_->word()->fontinfo;
    if (font_info) {
      // Font information available.
      *font_id = font_info->universal_id;
      *is_bold = font_info->is_bold();
      *is_italic = font_info->is_italic();
      *is_underlined = false; // TODO(rays) fix this!
      *is_monospace = font_info->is_fixed_pitch();
      *is_serif = font_info->is_serif();
      result = font_info->name;
    }
#endif // ndef DISABLED_LEGACY_ENGINE

    *is_smallcaps = it_->word()->small_caps;
  }

  if (!result) {
    *is_bold = false;
    *is_italic = false;
    *is_underlined = false;
    *is_monospace = false;
    *is_serif = false;
    *is_smallcaps = false;
    *font_id = -1;
  }

  return result;
}