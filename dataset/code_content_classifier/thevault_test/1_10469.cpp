static void empty_buckets(BLOCK *block,       // block to scan
                          OL_BUCKETS *buckets // output buckets
) {
  C_OUTLINE_LIST outlines; // outlines in block
                           // iterator
  C_OUTLINE_IT out_it = &outlines;
  auto start_scan = buckets->start_scan();
  if (start_scan == nullptr) {
    return;
  }
  C_OUTLINE_IT bucket_it = start_scan;
  C_BLOB_IT good_blobs = block->blob_list();
  C_BLOB_IT junk_blobs = block->reject_blobs();

  while (!bucket_it.empty()) {
    out_it.set_to_list(&outlines);
    C_OUTLINE_IT parent_it; // parent outline
    do {
      parent_it = bucket_it; // find outermost
      do {
        bucket_it.forward();
      } while (!bucket_it.at_first() &&
               !(*parent_it.data() < *bucket_it.data()));
    } while (!bucket_it.at_first());

    // move to new list
    out_it.add_after_then_move(parent_it.extract());
    // healthy blob
    bool good_blob = capture_children(buckets, &junk_blobs, &out_it);
    C_BLOB::ConstructBlobsFromOutlines(good_blob, &outlines, &good_blobs,
                                       &junk_blobs);

    if (auto l = buckets->scan_next())
      bucket_it.set_to_list(l);
    else
      break;
  }
}