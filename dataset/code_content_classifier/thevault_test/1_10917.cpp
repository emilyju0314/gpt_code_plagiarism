void RecodeBeamSearch::PushInitialDawgIfBetter(int code, int unichar_id,
                                               PermuterType permuter,
                                               bool start, bool end, float cert,
                                               NodeContinuation cont,
                                               const RecodeNode *prev,
                                               RecodeBeam *step) {
  RecodeNode *best_initial_dawg = &step->best_initial_dawgs_[cont];
  float score = cert;
  if (prev != nullptr) {
    score += prev->score;
  }
  if (best_initial_dawg->code < 0 || score > best_initial_dawg->score) {
    auto *initial_dawgs = new DawgPositionVector;
    dict_->default_dawgs(initial_dawgs, false);
    RecodeNode node(code, unichar_id, permuter, true, start, end, false, cert,
                    score, prev, initial_dawgs,
                    ComputeCodeHash(code, false, prev));
    *best_initial_dawg = node;
  }
}