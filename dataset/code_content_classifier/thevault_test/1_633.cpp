static std::vector<int> GenerateAllocFreeSeqs(int alloc_num) {
  std::vector<int> action_sequences;
  std::vector<int> allocate_sizes;

  action_sequences.reserve(alloc_num * 2);
  allocate_sizes.reserve(alloc_num);

  for (int i = 0; i < alloc_num; ++i) {
    action_sequences.push_back(i);
    action_sequences.push_back(i);

    // Size between 10k and 100k, make sure it is different
    int size = 10 * 1024 + random() % (90 * 1024);
    while (std::find(allocate_sizes.begin(), allocate_sizes.end(), size) != allocate_sizes.end()) {
      size = 10 * 1024 + random() % (90 * 1024);
    }

    allocate_sizes.push_back(size);
  }

  // Shuffle it
  for (int i = 0; i < alloc_num * 2; ++i) {
    int j = i + random() % (alloc_num * 2 - i);
    // Swap element at i and j
    std::swap(action_sequences[i], action_sequences[j]);
  }

  // Place the size in the sequence
  for (int i = 0; i < alloc_num * 2; ++i) {
    int idx = action_sequences[i];
    action_sequences[i] = allocate_sizes[idx];
  }

  return action_sequences;
}