void manual_seed(uint64_t seed) {
  auto defaultGenerator = getDefaultMLUGenerator();
  std::lock_guard<std::mutex> lock(defaultGenerator.mutex());
  defaultGenerator.set_current_seed(seed);
}