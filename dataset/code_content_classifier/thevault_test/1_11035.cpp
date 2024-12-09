bool ChoiceIterator::Next() {
  if (oemLSTM_ && LSTM_choices_ != nullptr && !LSTM_choices_->empty()) {
    if (LSTM_choice_it_ == LSTM_choices_->end() ||
        next(LSTM_choice_it_) == LSTM_choices_->end()) {
      return false;
    } else {
      ++LSTM_choice_it_;
      return true;
    }
  } else {
    if (choice_it_ == nullptr) {
      return false;
    }
    choice_it_->forward();
    return !choice_it_->cycled_list();
  }
}