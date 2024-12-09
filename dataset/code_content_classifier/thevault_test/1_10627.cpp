float ParamsModel::ComputeCost(const float features[]) const {
  float unnorm_score = 0.0;
  for (int f = 0; f < PTRAIN_NUM_FEATURE_TYPES; ++f) {
    unnorm_score += weights_vec_[pass_][f] * features[f];
  }
  return ClipToRange(-unnorm_score / kScoreScaleFactor, kMinFinalCost, kMaxFinalCost);
}