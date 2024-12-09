const char *ChoiceIterator::GetUTF8Text() const {
  if (oemLSTM_ && LSTM_choices_ != nullptr && !LSTM_choices_->empty()) {
    std::pair<const char *, float> choice = *LSTM_choice_it_;
    return choice.first;
  } else {
    if (choice_it_ == nullptr) {
      return nullptr;
    }
    UNICHAR_ID id = choice_it_->data()->unichar_id();
    return word_res_->uch_set->id_to_unichar_ext(id);
  }
}