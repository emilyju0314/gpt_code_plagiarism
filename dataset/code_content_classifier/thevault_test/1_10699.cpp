bool Tesseract::BelievableSuperscript(bool debug, const WERD_RES &word, float certainty_threshold,
                                      int *left_ok, int *right_ok) const {
  unsigned initial_ok_run_count = 0;
  unsigned ok_run_count = 0;
  float worst_certainty = 0.0f;
  const WERD_CHOICE &wc = *word.best_choice;

  const UnicityTable<FontInfo> &fontinfo_table = get_fontinfo_table();
  for (unsigned i = 0; i < wc.length(); i++) {
    TBLOB *blob = word.rebuild_word->blobs[i];
    UNICHAR_ID unichar_id = wc.unichar_id(i);
    float char_certainty = wc.certainty(i);
    bool bad_certainty = char_certainty < certainty_threshold;
    bool is_punc = wc.unicharset()->get_ispunctuation(unichar_id);
    bool is_italic = word.fontinfo && word.fontinfo->is_italic();
    BLOB_CHOICE *choice = word.GetBlobChoice(i);
    if (choice && fontinfo_table.size() > 0) {
      // Get better information from the specific choice, if available.
      int font_id1 = choice->fontinfo_id();
      bool font1_is_italic = font_id1 >= 0 ? fontinfo_table.at(font_id1).is_italic() : false;
      int font_id2 = choice->fontinfo_id2();
      is_italic = font1_is_italic && (font_id2 < 0 || fontinfo_table.at(font_id2).is_italic());
    }

    float height_fraction = 1.0f;
    float char_height = blob->bounding_box().height();
    float normal_height = char_height;
    if (wc.unicharset()->top_bottom_useful()) {
      int min_bot, max_bot, min_top, max_top;
      wc.unicharset()->get_top_bottom(unichar_id, &min_bot, &max_bot, &min_top, &max_top);
      float hi_height = max_top - max_bot;
      float lo_height = min_top - min_bot;
      normal_height = (hi_height + lo_height) / 2;
      if (normal_height >= kBlnXHeight) {
        // Only ding characters that we have decent information for because
        // they're supposed to be normal sized, not tiny specks or dashes.
        height_fraction = char_height / normal_height;
      }
    }
    bool bad_height = height_fraction < superscript_scaledown_ratio;

    if (debug) {
      if (is_italic) {
        tprintf(" Rejecting: superscript is italic.\n");
      }
      if (is_punc) {
        tprintf(" Rejecting: punctuation present.\n");
      }
      const char *char_str = wc.unicharset()->id_to_unichar(unichar_id);
      if (bad_certainty) {
        tprintf(
            " Rejecting: don't believe character %s with certainty %.2f "
            "which is less than threshold %.2f\n",
            char_str, char_certainty, certainty_threshold);
      }
      if (bad_height) {
        tprintf(
            " Rejecting: character %s seems too small @ %.2f versus "
            "expected %.2f\n",
            char_str, char_height, normal_height);
      }
    }
    if (bad_certainty || bad_height || is_punc || is_italic) {
      if (ok_run_count == i) {
        initial_ok_run_count = ok_run_count;
      }
      ok_run_count = 0;
    } else {
      ok_run_count++;
    }
    if (char_certainty < worst_certainty) {
      worst_certainty = char_certainty;
    }
  }
  bool all_ok = ok_run_count == wc.length();
  if (all_ok && debug) {
    tprintf(" Accept: worst revised certainty is %.2f\n", worst_certainty);
  }
  if (!all_ok) {
    if (left_ok) {
      *left_ok = initial_ok_run_count;
    }
    if (right_ok) {
      *right_ok = ok_run_count;
    }
  }
  return all_ok;
}