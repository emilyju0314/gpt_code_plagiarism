ROW_RES::ROW_RES(bool merge_similar_words, ROW *the_row) {
  WERD_IT word_it(the_row->word_list());
  WERD_RES_IT word_res_it(&word_res_list);
  WERD_RES *combo = nullptr; // current combination of fuzzies
  WERD *copy_word;

  char_count = 0;
  rej_count = 0;
  whole_word_rej_count = 0;

  row = the_row;
  bool add_next_word = false;
  TBOX union_box;
  float line_height =
      the_row->x_height() + the_row->ascenders() - the_row->descenders();
  for (word_it.mark_cycle_pt(); !word_it.cycled_list(); word_it.forward()) {
    auto *word_res = new WERD_RES(word_it.data());
    word_res->x_height = the_row->x_height();
    if (add_next_word) {
      ASSERT_HOST(combo != nullptr);
      // We are adding this word to the combination.
      word_res->part_of_combo = true;
      combo->copy_on(word_res);
    } else if (merge_similar_words) {
      union_box = word_res->word->bounding_box();
      add_next_word = !word_res->word->flag(W_REP_CHAR) &&
                      union_box.height() <= line_height * kMaxWordSizeRatio;
      word_res->odd_size = !add_next_word;
    }
    WERD *next_word = word_it.data_relative(1);
    if (merge_similar_words) {
      if (add_next_word && !next_word->flag(W_REP_CHAR)) {
        // Next word will be added on if all of the following are true:
        // Not a rep char.
        // Box height small enough.
        // Union box height small enough.
        // Horizontal gap small enough.
        TBOX next_box = next_word->bounding_box();
        int prev_right = union_box.right();
        union_box += next_box;
        if (next_box.height() > line_height * kMaxWordSizeRatio ||
            union_box.height() > line_height * kMaxLineSizeRatio ||
            next_box.left() > prev_right + line_height * kMaxWordGapRatio) {
          add_next_word = false;
        }
      }
      next_word->set_flag(W_FUZZY_NON, add_next_word);
    } else {
      add_next_word = next_word->flag(W_FUZZY_NON);
    }
    if (add_next_word) {
      if (combo == nullptr) {
        copy_word = new WERD;
        *copy_word = *(word_it.data()); // deep copy
        combo = new WERD_RES(copy_word);
        combo->x_height = the_row->x_height();
        combo->combination = true;
        word_res_it.add_to_end(combo);
      }
      word_res->part_of_combo = true;
    } else {
      combo = nullptr;
    }
    word_res_it.add_to_end(word_res);
  }
}