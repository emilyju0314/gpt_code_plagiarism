void WERD_RES::FakeClassifyWord(unsigned blob_count, BLOB_CHOICE **choices) {
  // Setup the WERD_RES.
  ASSERT_HOST(box_word != nullptr);
  ASSERT_HOST(blob_count == box_word->length());
  ClearWordChoices();
  ClearRatings();
  ratings = new MATRIX(blob_count, 1);
  for (unsigned c = 0; c < blob_count; ++c) {
    auto *choice_list = new BLOB_CHOICE_LIST;
    BLOB_CHOICE_IT choice_it(choice_list);
    choice_it.add_after_then_move(choices[c]);
    ratings->put(c, c, choice_list);
  }
  FakeWordFromRatings(TOP_CHOICE_PERM);
  reject_map.initialise(blob_count);
  best_state.clear();
  best_state.resize(blob_count, 1);
  done = true;
}