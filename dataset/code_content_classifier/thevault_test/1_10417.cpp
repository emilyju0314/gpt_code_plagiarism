void Tesseract::make_reject_map(WERD_RES *word, ROW *row, int16_t pass) {
  flip_0O(word);
  check_debug_pt(word, -1); // For trap only
  set_done(word, pass);     // Set acceptance
  word->reject_map.initialise(word->best_choice->unichar_lengths().length());
  reject_blanks(word);
  /*
0: Rays original heuristic - the baseline
*/
  if (tessedit_reject_mode == 0) {
    if (!word->done) {
      reject_poor_matches(word);
    }
  } else if (tessedit_reject_mode == 5) {
    /*
5: Reject I/1/l from words where there is no strong contextual confirmation;
  the whole of any unacceptable words (incl PERM rej of dubious 1/I/ls);
  and the whole of any words which are very small
*/
    if (kBlnXHeight / word->denorm.y_scale() <= min_sane_x_ht_pixels) {
      word->reject_map.rej_word_small_xht();
    } else {
      one_ell_conflict(word, true);
      /*
  Originally the code here just used the done flag. Now I have duplicated
  and unpacked the conditions for setting the done flag so that each
  mechanism can be turned on or off independently. This works WITHOUT
  affecting the done flag setting.
*/
      if (rej_use_tess_accepted && !word->tess_accepted) {
        word->reject_map.rej_word_not_tess_accepted();
      }

      if (rej_use_tess_blanks &&
          (strchr(word->best_choice->unichar_string().c_str(), ' ') != nullptr)) {
        word->reject_map.rej_word_contains_blanks();
      }

      WERD_CHOICE *best_choice = word->best_choice;
      if (rej_use_good_perm) {
        if ((best_choice->permuter() == SYSTEM_DAWG_PERM ||
             best_choice->permuter() == FREQ_DAWG_PERM ||
             best_choice->permuter() == USER_DAWG_PERM) &&
            (!rej_use_sensible_wd ||
             acceptable_word_string(*word->uch_set, best_choice->unichar_string().c_str(),
                                    best_choice->unichar_lengths().c_str()) != AC_UNACCEPTABLE)) {
          // PASSED TEST
        } else if (best_choice->permuter() == NUMBER_PERM) {
          if (rej_alphas_in_number_perm) {
            for (int i = 0, offset = 0; best_choice->unichar_string()[offset] != '\0';
                 offset += best_choice->unichar_lengths()[i++]) {
              if (word->reject_map[i].accepted() &&
                  word->uch_set->get_isalpha(best_choice->unichar_string().c_str() + offset,
                                             best_choice->unichar_lengths()[i])) {
                word->reject_map[i].setrej_bad_permuter();
              }
              // rej alpha
            }
          }
        } else {
          word->reject_map.rej_word_bad_permuter();
        }
      }
      /* Ambig word rejection was here once !!*/
    }
  } else {
    tprintf("BAD tessedit_reject_mode\n");
    ASSERT_HOST("Fatal error encountered!" == nullptr);
  }

  if (tessedit_image_border > -1) {
    reject_edge_blobs(word);
  }

  check_debug_pt(word, 10);
  if (tessedit_rejection_debug) {
    tprintf("Permuter Type = %d\n", word->best_choice->permuter());
    tprintf("Certainty: %f     Rating: %f\n", word->best_choice->certainty(),
            word->best_choice->rating());
    tprintf("Dict word: %d\n", dict_word(*(word->best_choice)));
  }

  flip_hyphens(word);
  check_debug_pt(word, 20);
}