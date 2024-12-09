void Plumbing::Update(float learning_rate, float momentum, float adam_beta, int num_samples) {
  for (size_t i = 0; i < stack_.size(); ++i) {
    if (network_flags_ & NF_LAYER_SPECIFIC_LR) {
      if (i < learning_rates_.size()) {
        learning_rate = learning_rates_[i];
      } else {
        learning_rates_.push_back(learning_rate);
      }
    }
    if (stack_[i]->IsTraining()) {
      stack_[i]->Update(learning_rate, momentum, adam_beta, num_samples);
    }
  }
}