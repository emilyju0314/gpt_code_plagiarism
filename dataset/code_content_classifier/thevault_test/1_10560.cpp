bool OrientationDetector::detect_blob(BLOB_CHOICE_LIST *scores) {
  float blob_o_score[4] = {0.0f, 0.0f, 0.0f, 0.0f};
  float total_blob_o_score = 0.0f;

  for (int i = 0; i < 4; ++i) {
    BLOB_CHOICE_IT choice_it(scores + i);
    if (!choice_it.empty()) {
      BLOB_CHOICE *choice = nullptr;
      if (allowed_scripts_ != nullptr && !allowed_scripts_->empty()) {
        // Find the top choice in an allowed script.
        for (choice_it.mark_cycle_pt(); !choice_it.cycled_list() && choice == nullptr;
             choice_it.forward()) {
          int choice_script = choice_it.data()->script_id();
          unsigned s = 0;
          for (s = 0; s < allowed_scripts_->size(); ++s) {
            if ((*allowed_scripts_)[s] == choice_script) {
              choice = choice_it.data();
              break;
            }
          }
        }
      } else {
        choice = choice_it.data();
      }
      if (choice != nullptr) {
        // The certainty score ranges between [-20,0]. This is converted here to
        // [0,1], with 1 indicating best match.
        blob_o_score[i] = 1 + 0.05 * choice->certainty();
        total_blob_o_score += blob_o_score[i];
      }
    }
  }
  if (total_blob_o_score == 0.0) {
    return false;
  }
  // Fill in any blanks with the worst score of the others. This is better than
  // picking an arbitrary probability for it and way better than -inf.
  float worst_score = 0.0f;
  int num_good_scores = 0;
  for (float f : blob_o_score) {
    if (f > 0.0f) {
      ++num_good_scores;
      if (worst_score == 0.0f || f < worst_score) {
        worst_score = f;
      }
    }
  }
  if (num_good_scores == 1) {
    // Lower worst if there is only one.
    worst_score /= 2.0f;
  }
  for (float &f : blob_o_score) {
    if (f == 0.0f) {
      f = worst_score;
      total_blob_o_score += worst_score;
    }
  }
  // Normalize the orientation scores for the blob and use them to
  // update the aggregated orientation score.
  for (int i = 0; total_blob_o_score != 0 && i < 4; ++i) {
    osr_->orientations[i] += std::log(blob_o_score[i] / total_blob_o_score);
  }

  // TODO(ranjith) Add an early exit test, based on min_orientation_margin,
  // as used in pagesegmain.cpp.
  return false;
}