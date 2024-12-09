PAGE_RES_IT *make_pseudo_word(PAGE_RES *page_res, const TBOX &selection_box) {
  PAGE_RES_IT pr_it(page_res);
  C_BLOB_LIST new_blobs;              // list of gathered blobs
  C_BLOB_IT new_blob_it = &new_blobs; // iterator

  for (WERD_RES *word_res = pr_it.word(); word_res != nullptr; word_res = pr_it.forward()) {
    WERD *word = word_res->word;
    if (word->bounding_box().overlap(selection_box)) {
      C_BLOB_IT blob_it(word->cblob_list());
      for (blob_it.mark_cycle_pt(); !blob_it.cycled_list(); blob_it.forward()) {
        C_BLOB *blob = blob_it.data();
        if (blob->bounding_box().overlap(selection_box)) {
          new_blob_it.add_after_then_move(C_BLOB::deep_copy(blob));
        }
      }
      if (!new_blobs.empty()) {
        WERD *pseudo_word = new WERD(&new_blobs, 1, nullptr);
        word_res = pr_it.InsertSimpleCloneWord(*word_res, pseudo_word);
        auto *it = new PAGE_RES_IT(page_res);
        while (it->word() != word_res && it->word() != nullptr) {
          it->forward();
        }
        ASSERT_HOST(it->word() == word_res);
        return it;
      }
    }
  }
  return nullptr;
}