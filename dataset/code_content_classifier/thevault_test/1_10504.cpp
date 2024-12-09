void Tesseract::split_and_recog_word(WERD_RES *word) {
  // Find the biggest blob gap in the chopped_word.
  int bestgap = -INT32_MAX;
  int split_index = 0;
  for (unsigned b = 1; b < word->chopped_word->NumBlobs(); ++b) {
    TBOX prev_box = word->chopped_word->blobs[b - 1]->bounding_box();
    TBOX blob_box = word->chopped_word->blobs[b]->bounding_box();
    int gap = blob_box.left() - prev_box.right();
    if (gap > bestgap) {
      bestgap = gap;
      split_index = b;
    }
  }
  ASSERT_HOST(split_index > 0);

  WERD_RES *word2 = nullptr;
  BlamerBundle *orig_bb = nullptr;
  split_word(word, split_index, &word2, &orig_bb);

  // Recognize the first part of the word.
  recog_word_recursive(word);
  // Recognize the second part of the word.
  recog_word_recursive(word2);

  join_words(word, word2, orig_bb);
}