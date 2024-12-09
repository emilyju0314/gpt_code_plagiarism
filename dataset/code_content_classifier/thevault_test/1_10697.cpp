bool Tesseract::SubAndSuperscriptFix(WERD_RES *word) {
  if (word->tess_failed || word->word->flag(W_REP_CHAR) || !word->best_choice) {
    return false;
  }
  int num_leading, num_trailing;
  ScriptPos sp_leading, sp_trailing;
  float leading_certainty, trailing_certainty;
  float avg_certainty, unlikely_threshold;

  // Calculate the number of whole suspicious characters at the edges.
  GetSubAndSuperscriptCandidates(word, &num_leading, &sp_leading, &leading_certainty, &num_trailing,
                                 &sp_trailing, &trailing_certainty, &avg_certainty,
                                 &unlikely_threshold);

  const char *leading_pos = sp_leading == SP_SUBSCRIPT ? "sub" : "super";
  const char *trailing_pos = sp_trailing == SP_SUBSCRIPT ? "sub" : "super";

  int num_blobs = word->best_choice->length();

  // Calculate the remainder (partial characters) at the edges.
  // This accounts for us having classified the best version of
  // a word as [speaker?'] when it was instead [speaker.^{21}]
  // (that is we accidentally thought the 2 was attached to the period).
  int num_remainder_leading = 0, num_remainder_trailing = 0;
  if (num_leading + num_trailing < num_blobs && unlikely_threshold < 0.0) {
    int super_y_bottom = kBlnBaselineOffset + kBlnXHeight * superscript_min_y_bottom;
    int sub_y_top = kBlnBaselineOffset + kBlnXHeight * subscript_max_y_top;
    int last_word_char = num_blobs - 1 - num_trailing;
    float last_char_certainty = word->best_choice->certainty(last_word_char);
    if (word->best_choice->unichar_id(last_word_char) != 0 &&
        last_char_certainty <= unlikely_threshold) {
      ScriptPos rpos;
      YOutlierPieces(word, last_word_char, super_y_bottom, sub_y_top, nullptr, nullptr, &rpos,
                     &num_remainder_trailing);
      if (num_trailing > 0 && rpos != sp_trailing) {
        num_remainder_trailing = 0;
      }
      if (num_remainder_trailing > 0 && last_char_certainty < trailing_certainty) {
        trailing_certainty = last_char_certainty;
      }
    }
    bool another_blob_available =
        (num_remainder_trailing == 0) || num_leading + num_trailing + 1 < num_blobs;
    int first_char_certainty = word->best_choice->certainty(num_leading);
    if (another_blob_available && word->best_choice->unichar_id(num_leading) != 0 &&
        first_char_certainty <= unlikely_threshold) {
      ScriptPos lpos;
      YOutlierPieces(word, num_leading, super_y_bottom, sub_y_top, &lpos, &num_remainder_leading,
                     nullptr, nullptr);
      if (num_leading > 0 && lpos != sp_leading) {
        num_remainder_leading = 0;
      }
      if (num_remainder_leading > 0 && first_char_certainty < leading_certainty) {
        leading_certainty = first_char_certainty;
      }
    }
  }

  // If nothing to do, bail now.
  if (num_leading + num_trailing + num_remainder_leading + num_remainder_trailing == 0) {
    return false;
  }

  if (superscript_debug >= 1) {
    tprintf("Candidate for superscript detection: %s (",
            word->best_choice->unichar_string().c_str());
    if (num_leading || num_remainder_leading) {
      tprintf("%d.%d %s-leading ", num_leading, num_remainder_leading, leading_pos);
    }
    if (num_trailing || num_remainder_trailing) {
      tprintf("%d.%d %s-trailing ", num_trailing, num_remainder_trailing, trailing_pos);
    }
    tprintf(")\n");
  }
  if (superscript_debug >= 3) {
    word->best_choice->print();
  }
  if (superscript_debug >= 2) {
    tprintf(" Certainties -- Average: %.2f  Unlikely thresh: %.2f  ", avg_certainty,
            unlikely_threshold);
    if (num_leading) {
      tprintf("Orig. leading (min): %.2f  ", leading_certainty);
    }
    if (num_trailing) {
      tprintf("Orig. trailing (min): %.2f  ", trailing_certainty);
    }
    tprintf("\n");
  }

  // We've now calculated the number of rebuilt blobs we want to carve off.
  // However, split_word() works from TBLOBs in chopped_word, so we need to
  // convert to those.
  int num_chopped_leading = LeadingUnicharsToChopped(word, num_leading) + num_remainder_leading;
  int num_chopped_trailing = TrailingUnicharsToChopped(word, num_trailing) + num_remainder_trailing;

  int retry_leading = 0;
  int retry_trailing = 0;
  bool is_good = false;
  WERD_RES *revised = TrySuperscriptSplits(num_chopped_leading, leading_certainty, sp_leading,
                                           num_chopped_trailing, trailing_certainty, sp_trailing,
                                           word, &is_good, &retry_leading, &retry_trailing);
  if (is_good) {
    word->ConsumeWordResults(revised);
  } else if (retry_leading || retry_trailing) {
    int retry_chopped_leading = LeadingUnicharsToChopped(revised, retry_leading);
    int retry_chopped_trailing = TrailingUnicharsToChopped(revised, retry_trailing);
    WERD_RES *revised2 = TrySuperscriptSplits(
        retry_chopped_leading, leading_certainty, sp_leading, retry_chopped_trailing,
        trailing_certainty, sp_trailing, revised, &is_good, &retry_leading, &retry_trailing);
    if (is_good) {
      word->ConsumeWordResults(revised2);
    }
    delete revised2;
  }
  delete revised;
  return is_good;
}