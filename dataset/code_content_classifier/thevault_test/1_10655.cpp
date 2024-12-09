void Tesseract::SearchWords(PointerVector<WERD_RES> *words) {
  // Run the segmentation search on the network outputs and make a BoxWord
  // for each of the output words.
  // If we drop a word as junk, then there is always a space in front of the
  // next.
  const Dict *stopper_dict = lstm_recognizer_->GetDict();
  if (stopper_dict == nullptr) {
    stopper_dict = &getDict();
  }
  for (unsigned w = 0; w < words->size(); ++w) {
    WERD_RES *word = (*words)[w];
    if (word->best_choice == nullptr) {
      // It is a dud.
      word->SetupFake(lstm_recognizer_->GetUnicharset());
    } else {
      // Set the best state.
      for (unsigned i = 0; i < word->best_choice->length(); ++i) {
        int length = word->best_choice->state(i);
        word->best_state.push_back(length);
      }
      word->reject_map.initialise(word->best_choice->length());
      word->tess_failed = false;
      word->tess_accepted = true;
      word->tess_would_adapt = false;
      word->done = true;
      word->tesseract = this;
      float word_certainty = std::min(word->space_certainty, word->best_choice->certainty());
      word_certainty *= kCertaintyScale;
      if (getDict().stopper_debug_level >= 1) {
        tprintf("Best choice certainty=%g, space=%g, scaled=%g, final=%g\n",
                word->best_choice->certainty(), word->space_certainty,
                std::min(word->space_certainty, word->best_choice->certainty()) * kCertaintyScale,
                word_certainty);
        word->best_choice->print();
      }
      word->best_choice->set_certainty(word_certainty);

      word->tess_accepted = stopper_dict->AcceptableResult(word);
    }
  }
}