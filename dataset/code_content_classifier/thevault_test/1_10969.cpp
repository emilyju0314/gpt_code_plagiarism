void FullyConnected::CountAlternators(const Network &other, TFloat *same, TFloat *changed) const {
  ASSERT_HOST(other.type() == type_);
  const auto *fc = static_cast<const FullyConnected *>(&other);
  weights_.CountAlternators(fc->weights_, same, changed);
}