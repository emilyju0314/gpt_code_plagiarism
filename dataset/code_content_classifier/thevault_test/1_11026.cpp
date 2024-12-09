const void *LTRResultIterator::GetParamsTrainingBundle() const {
  return (it_->word() != nullptr && it_->word()->blamer_bundle != nullptr)
             ? &(it_->word()->blamer_bundle->params_training_bundle())
             : nullptr;
}