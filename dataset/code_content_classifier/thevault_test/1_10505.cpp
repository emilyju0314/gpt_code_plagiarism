void Tesseract::split_word(WERD_RES *word, unsigned split_pt, WERD_RES **right_piece,
                           BlamerBundle **orig_blamer_bundle) const {
  ASSERT_HOST(split_pt > 0 && split_pt < word->chopped_word->NumBlobs());

  // Save a copy of the blamer bundle so we can try to reconstruct it below.
  BlamerBundle *orig_bb = word->blamer_bundle ? new BlamerBundle(*word->blamer_bundle) : nullptr;

  auto *word2 = new WERD_RES(*word);

  // blow away the copied chopped_word, as we want to work with
  // the blobs from the input chopped_word so seam_arrays can be merged.
  TWERD *chopped = word->chopped_word;
  auto *chopped2 = new TWERD;
  chopped2->blobs.reserve(chopped->NumBlobs() - split_pt);
  for (auto i = split_pt; i < chopped->NumBlobs(); ++i) {
    chopped2->blobs.push_back(chopped->blobs[i]);
  }
  chopped->blobs.resize(split_pt);
  word->chopped_word = nullptr;
  delete word2->chopped_word;
  word2->chopped_word = nullptr;

  const UNICHARSET &unicharset = *word->uch_set;
  word->ClearResults();
  word2->ClearResults();
  word->chopped_word = chopped;
  word2->chopped_word = chopped2;
  word->SetupBasicsFromChoppedWord(unicharset);
  word2->SetupBasicsFromChoppedWord(unicharset);

  // Try to adjust the blamer bundle.
  if (orig_bb != nullptr) {
    // TODO(rays) Looks like a leak to me.
    // orig_bb should take, rather than copy.
    word->blamer_bundle = new BlamerBundle();
    word2->blamer_bundle = new BlamerBundle();
    orig_bb->SplitBundle(chopped->blobs.back()->bounding_box().right(),
                         word2->chopped_word->blobs[0]->bounding_box().left(), wordrec_debug_blamer,
                         word->blamer_bundle, word2->blamer_bundle);
  }

  *right_piece = word2;
  *orig_blamer_bundle = orig_bb;
}