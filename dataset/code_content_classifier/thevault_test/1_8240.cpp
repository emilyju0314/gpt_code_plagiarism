int BigramSegmenter::GetTermIdAndUnigramCost(
    const char *token_string,
    TraverseState *traverse_state,
    double *right_cost) {

  ReimuTrie::int32 term_id = -1, uterm_id = -1;

  if (traverse_state->index_end == false) {
    bool exist = index_->Traverse(
        &traverse_state->index_from,
        token_string,
        &term_id,
        -1);
    if (exist == false) {
      traverse_state->index_end = true;
      term_id = -1;
    }
    if (term_id >= 0) {
      *right_cost = unigram_cost_->get(term_id);
      LOG("System unigram find: %d, cost = %f\n", term_id, *right_cost);
    }
  }

  if (traverse_state->userindex_end == false) {
    bool exist = user_index_->Traverse(
        &traverse_state->userindex_from,
        token_string,
        &uterm_id,
        -1);
    if (exist == false) {
      traverse_state->userindex_end = true;
      uterm_id = -1;
    }
    if (uterm_id >= 0) {
      double cost = user_cost_->get(uterm_id - kUserTermIdStart);
      LOG("User unigram find: %d, cost = %f\n", uterm_id, cost);

      if (term_id < 0) {
        *right_cost = cost;

        // Use term id in user dictionary iff term-id in system dictionary not
        // exist
        term_id = uterm_id;
      } else if (cost != kDefaultCost) {
        // The word exists in both system and user index. So when the cost in 
        // user index is not `kDefaultCost`, use the cost in user index.
        *right_cost = cost;
      }
    }
  }

  return term_id;
}