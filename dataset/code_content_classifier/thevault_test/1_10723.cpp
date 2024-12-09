int TessClassifier::UnicharClassifySample(const TrainingSample &sample, Image page_pix, int debug,
                                          UNICHAR_ID keep_this,
                                          std::vector<UnicharRating> *results) {
  const int old_matcher_level = classify_->matcher_debug_level;
  const int old_matcher_flags = classify_->matcher_debug_flags;
  const int old_classify_level = classify_->classify_debug_level;
  if (debug) {
    // Explicitly set values of various control parameters to generate debug
    // output if required, restoring the old values after classifying.
    classify_->matcher_debug_level.set_value(2);
    classify_->matcher_debug_flags.set_value(25);
    classify_->classify_debug_level.set_value(3);
  }
  classify_->CharNormTrainingSample(pruner_only_, keep_this, sample, results);
  if (debug) {
    classify_->matcher_debug_level.set_value(old_matcher_level);
    classify_->matcher_debug_flags.set_value(old_matcher_flags);
    classify_->classify_debug_level.set_value(old_classify_level);
  }
  return results->size();
}