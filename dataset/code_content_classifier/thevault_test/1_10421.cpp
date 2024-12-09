void Tesseract::reject_mostly_rejects(WERD_RES *word) {
  /* Reject the whole of the word if the fraction of rejects exceeds a limit */

  if (static_cast<float>(word->reject_map.reject_count()) / word->reject_map.length() >=
      rej_whole_of_mostly_reject_word_fract) {
    word->reject_map.rej_word_mostly_rej();
  }
}