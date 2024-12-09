bool Plumbing::DeSerialize(TFile *fp) {
  for (auto data : stack_) {
    delete data;
  }
  stack_.clear();
  no_ = 0; // We will be modifying this as we AddToStack.
  uint32_t size;
  if (!fp->DeSerialize(&size)) {
    return false;
  }
  for (uint32_t i = 0; i < size; ++i) {
    Network *network = CreateFromFile(fp);
    if (network == nullptr) {
      return false;
    }
    AddToStack(network);
  }
  if ((network_flags_ & NF_LAYER_SPECIFIC_LR) && !fp->DeSerialize(learning_rates_)) {
    return false;
  }
  return true;
}