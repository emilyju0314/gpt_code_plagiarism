float compute_reject_threshold(WERD_CHOICE *word) {
  float threshold;      // rejection threshold
  float bestgap = 0.0f; // biggest gap
  float gapstart;       // bottom of gap

  auto blob_count = word->length();
  std::vector<float> ratings;
  ratings.reserve(blob_count);
  for (unsigned i = 0; i < blob_count; ++i) {
    ratings.push_back(word->certainty(i));
  }
  std::sort(ratings.begin(), ratings.end());
  gapstart = ratings[0] - 1; // all reject if none better
  if (blob_count >= 3) {
    for (unsigned index = 0; index < blob_count - 1; index++) {
      if (ratings[index + 1] - ratings[index] > bestgap) {
        bestgap = ratings[index + 1] - ratings[index];
        // find biggest
        gapstart = ratings[index];
      }
    }
  }
  threshold = gapstart + bestgap / 2;

  return threshold;
}