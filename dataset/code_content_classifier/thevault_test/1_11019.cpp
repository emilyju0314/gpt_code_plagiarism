float LTRResultIterator::Confidence(PageIteratorLevel level) const {
  if (it_->word() == nullptr) {
    return 0.0f; // Already at the end!
  }
  float mean_certainty = 0.0f;
  int certainty_count = 0;
  PAGE_RES_IT res_it(*it_);
  WERD_CHOICE *best_choice = res_it.word()->best_choice;
  ASSERT_HOST(best_choice != nullptr);
  switch (level) {
    case RIL_BLOCK:
      do {
        best_choice = res_it.word()->best_choice;
        ASSERT_HOST(best_choice != nullptr);
        mean_certainty += best_choice->certainty();
        ++certainty_count;
        res_it.forward();
      } while (res_it.block() == res_it.prev_block());
      break;
    case RIL_PARA:
      do {
        best_choice = res_it.word()->best_choice;
        ASSERT_HOST(best_choice != nullptr);
        mean_certainty += best_choice->certainty();
        ++certainty_count;
        res_it.forward();
      } while (res_it.block() == res_it.prev_block() &&
               res_it.row()->row->para() == res_it.prev_row()->row->para());
      break;
    case RIL_TEXTLINE:
      do {
        best_choice = res_it.word()->best_choice;
        ASSERT_HOST(best_choice != nullptr);
        mean_certainty += best_choice->certainty();
        ++certainty_count;
        res_it.forward();
      } while (res_it.row() == res_it.prev_row());
      break;
    case RIL_WORD:
      mean_certainty += best_choice->certainty();
      ++certainty_count;
      break;
    case RIL_SYMBOL:
      mean_certainty += best_choice->certainty(blob_index_);
      ++certainty_count;
  }
  if (certainty_count > 0) {
    mean_certainty /= certainty_count;
    return ClipToRange(100 + 5 * mean_certainty, 0.0f, 100.0f);
  }
  return 0.0f;
}