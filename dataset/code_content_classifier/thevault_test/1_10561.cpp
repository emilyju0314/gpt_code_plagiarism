void ScriptDetector::detect_blob(BLOB_CHOICE_LIST *scores) {
  for (int i = 0; i < 4; ++i) {
    bool done[kMaxNumberOfScripts] = {false};

    BLOB_CHOICE_IT choice_it;
    choice_it.set_to_list(scores + i);

    float prev_score = -1;
    int script_count = 0;
    int prev_id = -1;
    int prev_fontinfo_id = -1;
    const char *prev_unichar = "";
    const char *unichar = "";

    for (choice_it.mark_cycle_pt(); !choice_it.cycled_list(); choice_it.forward()) {
      BLOB_CHOICE *choice = choice_it.data();
      int id = choice->script_id();
      if (allowed_scripts_ != nullptr && !allowed_scripts_->empty()) {
        // Check that the choice is in an allowed script.
        size_t s = 0;
        for (s = 0; s < allowed_scripts_->size(); ++s) {
          if ((*allowed_scripts_)[s] == id) {
            break;
          }
        }
        if (s == allowed_scripts_->size()) {
          continue; // Not found in list.
        }
      }
      // Script already processed before.
      if (done[id]) {
        continue;
      }
      done[id] = true;

      unichar = tess_->unicharset.id_to_unichar(choice->unichar_id());
      // Save data from the first match
      if (prev_score < 0) {
        prev_score = -choice->certainty();
        script_count = 1;
        prev_id = id;
        prev_unichar = unichar;
        prev_fontinfo_id = choice->fontinfo_id();
      } else if (-choice->certainty() < prev_score + kNonAmbiguousMargin) {
        ++script_count;
      }

      if (strlen(prev_unichar) == 1) {
        if (unichar[0] >= '0' && unichar[0] <= '9') {
          break;
        }
      }

      // if script_count is >= 2, character is ambiguous, skip other matches
      // since they are useless.
      if (script_count >= 2) {
        break;
      }
    }
    // Character is non ambiguous
    if (script_count == 1) {
      // Update the score of the winning script
      osr_->scripts_na[i][prev_id] += 1.0;

      // Workaround for Fraktur
      if (prev_id == latin_id_) {
        if (prev_fontinfo_id >= 0) {
          const tesseract::FontInfo &fi = tess_->get_fontinfo_table().at(prev_fontinfo_id);
          // printf("Font: %s i:%i b:%i f:%i s:%i k:%i (%s)\n", fi.name,
          //       fi.is_italic(), fi.is_bold(), fi.is_fixed_pitch(),
          //       fi.is_serif(), fi.is_fraktur(),
          //       prev_unichar);
          if (fi.is_fraktur()) {
            osr_->scripts_na[i][prev_id] -= 1.0;
            osr_->scripts_na[i][fraktur_id_] += 1.0;
          }
        }
      }

      // Update Japanese / Korean pseudo-scripts
      if (prev_id == katakana_id_) {
        osr_->scripts_na[i][japanese_id_] += 1.0;
      }
      if (prev_id == hiragana_id_) {
        osr_->scripts_na[i][japanese_id_] += 1.0;
      }
      if (prev_id == hangul_id_) {
        osr_->scripts_na[i][korean_id_] += 1.0;
      }
      if (prev_id == han_id_) {
        osr_->scripts_na[i][korean_id_] += kHanRatioInKorean;
        osr_->scripts_na[i][japanese_id_] += kHanRatioInJapanese;
      }
    }
  } // iterate over each orientation
}