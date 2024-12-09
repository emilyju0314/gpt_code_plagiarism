float ChoiceIterator::Confidence() const {
  float confidence;
  if (oemLSTM_ && LSTM_choices_ != nullptr && !LSTM_choices_->empty()) {
    std::pair<const char *, float> choice = *LSTM_choice_it_;
    confidence = 100 - rating_coefficient_ * choice.second;
  } else {
    if (choice_it_ == nullptr) {
      return 0.0f;
    }
    confidence = 100 + 5 * choice_it_->data()->certainty();
  }
  return ClipToRange(confidence, 0.0f, 100.0f);
}