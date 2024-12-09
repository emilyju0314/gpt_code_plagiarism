inline double BigramSegmenter::CalculateBigramCost(int left_id,
                                                   int right_id,
                                                   double left_cost,
                                                   double right_cost) {
  double cost;

  // If bigram is disabled
  if (bigram_cost_ == NULL) return left_cost + right_cost;

  int64_t key = (static_cast<int64_t>(left_id) << 32) + right_id;
  const float *it = bigram_cost_->Find(key);
  if (it != NULL) {
    // if have bigram data use p(x_n+1|x_n) = p(x_n+1, x_n) / p(x_n)
    cost = left_cost + (*it - unigram_cost_->get(left_id));
    LOG("Bigram find: (%d, %d) cost = %f\n",
        left_id,
        right_id,
        cost - left_cost);
  } else {
    cost = left_cost + right_cost;
  }

  return cost;
}