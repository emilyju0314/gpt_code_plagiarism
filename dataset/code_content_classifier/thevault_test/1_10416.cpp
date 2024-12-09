void Tesseract::set_done(WERD_RES *word, int16_t pass) {
  word->done =
      word->tess_accepted && (strchr(word->best_choice->unichar_string().c_str(), ' ') == nullptr);
  bool word_is_ambig = word->best_choice->dangerous_ambig_found();
  bool word_from_dict = word->best_choice->permuter() == SYSTEM_DAWG_PERM ||
                        word->best_choice->permuter() == FREQ_DAWG_PERM ||
                        word->best_choice->permuter() == USER_DAWG_PERM;
  if (word->done && (pass == 1) && (!word_from_dict || word_is_ambig) &&
      one_ell_conflict(word, false)) {
    if (tessedit_rejection_debug) {
      tprintf("one_ell_conflict detected\n");
    }
    word->done = false;
  }
  if (word->done &&
      ((!word_from_dict && word->best_choice->permuter() != NUMBER_PERM) || word_is_ambig)) {
    if (tessedit_rejection_debug) {
      tprintf("non-dict or ambig word detected\n");
    }
    word->done = false;
  }
  if (tessedit_rejection_debug) {
    tprintf("set_done(): done=%d\n", word->done);
    word->best_choice->print("");
  }
}