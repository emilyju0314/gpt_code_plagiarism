void Wordrec::InitialSegSearch(WERD_RES *word_res, LMPainPoints *pain_points,
                               std::vector<SegSearchPending> *pending,
                               BestChoiceBundle *best_choice_bundle, BlamerBundle *blamer_bundle) {
  if (segsearch_debug_level > 0) {
    tprintf("Starting SegSearch on ratings matrix%s:\n",
            wordrec_enable_assoc ? " (with assoc)" : "");
    word_res->ratings->print(getDict().getUnicharset());
  }

  pain_points->GenerateInitial(word_res);

  // Compute scaling factor that will help us recover blob outline length
  // from classifier rating and certainty for the blob.
  float rating_cert_scale = -1.0 * getDict().certainty_scale / rating_scale;

  language_model_->InitForWord(prev_word_best_choice_, assume_fixed_pitch_char_segment,
                               segsearch_max_char_wh_ratio, rating_cert_scale);

  // Initialize blamer-related information: map character boxes recorded in
  // blamer_bundle->norm_truth_word to the corresponding i,j indices in the
  // ratings matrix. We expect this step to succeed, since when running the
  // chopper we checked that the correct chops are present.
  if (blamer_bundle != nullptr) {
    blamer_bundle->SetupCorrectSegmentation(word_res->chopped_word, wordrec_debug_blamer);
  }

  // pending[col] tells whether there is update work to do to combine
  // best_choice_bundle->beam[col - 1] with some BLOB_CHOICEs in matrix[col, *].
  // As the language model state is updated, pending entries are modified to
  // minimize duplication of work. It is important that during the update the
  // children are considered in the non-decreasing order of their column, since
  // this guarantees that all the parents would be up to date before an update
  // of a child is done.
  pending->clear();
  pending->resize(word_res->ratings->dimension(), SegSearchPending());

  // Search the ratings matrix for the initial best path.
  (*pending)[0].SetColumnClassified();
  UpdateSegSearchNodes(rating_cert_scale, 0, pending, word_res, pain_points, best_choice_bundle,
                       blamer_bundle);
}