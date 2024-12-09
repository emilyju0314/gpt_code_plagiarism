char *ResultIterator::GetUTF8Text(PageIteratorLevel level) const {
  if (it_->word() == nullptr) {
    return nullptr; // Already at the end!
  }
  std::string text;
  switch (level) {
    case RIL_BLOCK: {
      ResultIterator pp(*this);
      do {
        pp.AppendUTF8ParagraphText(&text);
      } while (pp.Next(RIL_PARA) && pp.it_->block() == it_->block());
    } break;
    case RIL_PARA:
      AppendUTF8ParagraphText(&text);
      break;
    case RIL_TEXTLINE: {
      ResultIterator it(*this);
      it.MoveToLogicalStartOfTextline();
      it.IterateAndAppendUTF8TextlineText(&text);
    } break;
    case RIL_WORD:
      AppendUTF8WordText(&text);
      break;
    case RIL_SYMBOL: {
      bool reading_direction_is_ltr = current_paragraph_is_ltr_ ^ in_minor_direction_;
      if (at_beginning_of_minor_run_) {
        text += reading_direction_is_ltr ? kLRM : kRLM;
      }
      text = it_->word()->BestUTF8(blob_index_, false);
      if (IsAtFinalSymbolOfWord()) {
        AppendSuffixMarks(&text);
      }
    } break;
  }
  int length = text.length() + 1;
  char *result = new char[length];
  strncpy(result, text.c_str(), length);
  return result;
}