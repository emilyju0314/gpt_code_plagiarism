std::tuple<std::unique_ptr<SuperGeniusTrie>, std::set<Buffer>> generateRandomTrie(
    size_t keys_num,
    size_t max_key_length = 32,
    size_t key_alphabet_size = 16) noexcept {
  std::tuple<std::unique_ptr<SuperGeniusTrie>, std::set<Buffer>> res;
  auto trie = std::make_unique<SuperGeniusTrieImpl>();
  std::mt19937 eng(5489u);  // explicitly set default seed
  std::uniform_int_distribution<std::mt19937::result_type> key_dist(
      0, key_alphabet_size);
  std::uniform_int_distribution<std::mt19937::result_type> length_dist(
      1, max_key_length);
  auto key_gen = std::bind(key_dist, eng);
  auto key_length_gen = std::bind(length_dist, eng);

  auto &keys = std::get<1>(res);
  for (size_t i = 0; i < keys_num; i++) {
    sgns::base::Buffer key(key_length_gen(), 0);
    std::generate(key.begin(), key.end(), std::ref(key_gen));
    EXPECT_OUTCOME_TRUE_1(trie->put(key, key));
    keys.emplace(std::move(key));
  }
  std::get<0>(res) = std::move(trie);
  return res;
}