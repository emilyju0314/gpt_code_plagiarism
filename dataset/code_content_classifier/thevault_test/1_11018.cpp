char *LTRResultIterator::GetUTF8Text(PageIteratorLevel level) const {
  if (it_->word() == nullptr) {
    return nullptr; // Already at the end!
  }
  std::string text;
  PAGE_RES_IT res_it(*it_);
  WERD_CHOICE *best_choice = res_it.word()->best_choice;
  ASSERT_HOST(best_choice != nullptr);
  if (level == RIL_SYMBOL) {
    text = res_it.word()->BestUTF8(blob_index_, false);
  } else if (level == RIL_WORD) {
    text = best_choice->unichar_string();
  } else {
    bool eol = false; // end of line?
    bool eop = false; // end of paragraph?
    do {              // for each paragraph in a block
      do {            // for each text line in a paragraph
        do {          // for each word in a text line
          best_choice = res_it.word()->best_choice;
          ASSERT_HOST(best_choice != nullptr);
          text += best_choice->unichar_string();
          text += " ";
          res_it.forward();
          eol = res_it.row() != res_it.prev_row();
        } while (!eol);
        text.resize(text.length() - 1);
        text += line_separator_;
        eop = res_it.block() != res_it.prev_block() ||
              res_it.row()->row->para() != res_it.prev_row()->row->para();
      } while (level != RIL_TEXTLINE && !eop);
      if (eop) {
        text += paragraph_separator_;
      }
    } while (level == RIL_BLOCK && res_it.block() == res_it.prev_block());
  }
  int length = text.length() + 1;
  char *result = new char[length];
  strncpy(result, text.c_str(), length);
  return result;
}