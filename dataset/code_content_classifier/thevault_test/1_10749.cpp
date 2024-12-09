bool Plumbing::Serialize(TFile *fp) const {
  if (!Network::Serialize(fp)) {
    return false;
  }
  uint32_t size = stack_.size();
  // Can't use PointerVector::Serialize here as we need a special DeSerialize.
  if (!fp->Serialize(&size)) {
    return false;
  }
  for (uint32_t i = 0; i < size; ++i) {
    if (!stack_[i]->Serialize(fp)) {
      return false;
    }
  }
  if ((network_flags_ & NF_LAYER_SPECIFIC_LR) && !fp->Serialize(learning_rates_)) {
    return false;
  }
  return true;
}