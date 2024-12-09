static void ComputeBlobEnds(const WERD_RES &word, const TBOX &clip_box,
                            C_BLOB_LIST *next_word_blobs,
                            std::vector<int> *blob_ends) {
  C_BLOB_IT blob_it(word.word->cblob_list());
  for (int length : word.best_state) {
    // Get the bounding box of the fake blobs
    TBOX blob_box = blob_it.data()->bounding_box();
    blob_it.forward();
    for (int b = 1; b < length; ++b) {
      blob_box += blob_it.data()->bounding_box();
      blob_it.forward();
    }
    // This blob_box is crap, so for now we are only looking for the
    // boundaries between them.
    int blob_end = INT32_MAX;
    if (!blob_it.at_first() || next_word_blobs != nullptr) {
      if (blob_it.at_first()) {
        blob_it.set_to_list(next_word_blobs);
      }
      blob_end = (blob_box.right() + blob_it.data()->bounding_box().left()) / 2;
    }
    blob_end = ClipToRange<int>(blob_end, clip_box.left(), clip_box.right());
    blob_ends->push_back(blob_end);
  }
  blob_ends->back() = clip_box.right();
}