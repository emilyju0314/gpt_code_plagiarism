void Tesseract::recog_word_recursive(WERD_RES *word) {
  auto word_length = word->chopped_word->NumBlobs(); // no of blobs
  if (word_length > MAX_UNDIVIDED_LENGTH) {
    return split_and_recog_word(word);
  }
  cc_recog(word);
  word_length = word->rebuild_word->NumBlobs(); // No of blobs in output.

  // Do sanity checks and minor fixes on best_choice.
  if (word->best_choice->length() > word_length) {
    word->best_choice->make_bad(); // should never happen
    tprintf(
        "recog_word: Discarded long string \"%s\""
        " (%d characters vs %d blobs)\n",
        word->best_choice->unichar_string().c_str(), word->best_choice->length(), word_length);
    tprintf("Word is at:");
    word->word->bounding_box().print();
  }
  if (word->best_choice->length() < word_length) {
    UNICHAR_ID space_id = unicharset.unichar_to_id(" ");
    while (word->best_choice->length() < word_length) {
      word->best_choice->append_unichar_id(space_id, 1, 0.0, word->best_choice->certainty());
    }
  }
}