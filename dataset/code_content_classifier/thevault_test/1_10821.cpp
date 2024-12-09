int word_comparator(const void *word1p, const void *word2p) {
  const WERD *word1 = *reinterpret_cast<const WERD *const *>(word1p);
  const WERD *word2 = *reinterpret_cast<const WERD *const *>(word2p);
  return word1->bounding_box().left() - word2->bounding_box().left();
}