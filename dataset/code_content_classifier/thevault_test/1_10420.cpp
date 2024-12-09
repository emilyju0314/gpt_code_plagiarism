void Tesseract::dont_allow_1Il(WERD_RES *word) {
  int word_len = word->reject_map.length();
  const char *s = word->best_choice->unichar_string().c_str();
  const char *lengths = word->best_choice->unichar_lengths().c_str();
  bool accepted_1Il = false;

  for (int i = 0, offset = 0; i < word_len; offset += word->best_choice->unichar_lengths()[i++]) {
    if (word->reject_map[i].accepted()) {
      if (conflict_set_I_l_1.contains(s[offset])) {
        accepted_1Il = true;
      } else {
        if (word->uch_set->get_isalpha(s + offset, lengths[i]) ||
            word->uch_set->get_isdigit(s + offset, lengths[i])) {
          return; // >=1 non 1Il ch accepted
        }
      }
    }
  }
  if (!accepted_1Il) {
    return; // Nothing to worry about
  }

  for (int i = 0, offset = 0; i < word_len; offset += word->best_choice->unichar_lengths()[i++]) {
    if (conflict_set_I_l_1.contains(s[offset]) && word->reject_map[i].accepted()) {
      word->reject_map[i].setrej_postNN_1Il();
    }
  }
}