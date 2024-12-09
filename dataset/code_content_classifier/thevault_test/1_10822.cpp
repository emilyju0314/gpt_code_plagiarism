WERD *WERD::ConstructWerdWithNewBlobs(C_BLOB_LIST *all_blobs, C_BLOB_LIST *orphan_blobs) {
  C_BLOB_LIST current_blob_list;
  C_BLOB_IT werd_blobs_it(&current_blob_list);
  // Add the word's c_blobs.
  werd_blobs_it.add_list_after(cblob_list());

  // New blob list. These contain the blobs which will form the new word.
  C_BLOB_LIST new_werd_blobs;
  C_BLOB_IT new_blobs_it(&new_werd_blobs);

  // not_found_blobs contains the list of current word's blobs for which a
  // corresponding blob wasn't found in the input all_blobs list.
  C_BLOB_LIST not_found_blobs;
  C_BLOB_IT not_found_it(&not_found_blobs);
  not_found_it.move_to_last();

  werd_blobs_it.move_to_first();
  for (werd_blobs_it.mark_cycle_pt(); !werd_blobs_it.cycled_list(); werd_blobs_it.forward()) {
    C_BLOB *werd_blob = werd_blobs_it.extract();
    TBOX werd_blob_box = werd_blob->bounding_box();
    bool found = false;
    // Now find the corresponding blob for this blob in the all_blobs
    // list. For now, follow the inefficient method of pairwise
    // comparisons. Ideally, one can pre-bucket the blobs by row.
    C_BLOB_IT all_blobs_it(all_blobs);
    for (all_blobs_it.mark_cycle_pt(); !all_blobs_it.cycled_list(); all_blobs_it.forward()) {
      C_BLOB *a_blob = all_blobs_it.data();
      // Compute the overlap of the two blobs. If major, a_blob should
      // be added to the new blobs list.
      TBOX a_blob_box = a_blob->bounding_box();
      if (a_blob_box.null_box()) {
        tprintf("Bounding box couldn't be ascertained\n");
      }
      if (werd_blob_box.contains(a_blob_box) || werd_blob_box.major_overlap(a_blob_box)) {
        // Old blobs are from minimal splits, therefore are expected to be
        // bigger. The new small blobs should cover a significant portion.
        // This is it.
        all_blobs_it.extract();
        new_blobs_it.add_after_then_move(a_blob);
        found = true;
      }
    }
    if (!found) {
      not_found_it.add_after_then_move(werd_blob);
    } else {
      delete werd_blob;
    }
  }
  // Iterate over all not found blobs. Some of them may be due to
  // under-segmentation (which is OK, since the corresponding blob is already
  // in the list in that case.
  not_found_it.move_to_first();
  for (not_found_it.mark_cycle_pt(); !not_found_it.cycled_list(); not_found_it.forward()) {
    C_BLOB *not_found = not_found_it.data();
    TBOX not_found_box = not_found->bounding_box();
    C_BLOB_IT existing_blobs_it(new_blobs_it);
    for (existing_blobs_it.mark_cycle_pt(); !existing_blobs_it.cycled_list();
         existing_blobs_it.forward()) {
      C_BLOB *a_blob = existing_blobs_it.data();
      TBOX a_blob_box = a_blob->bounding_box();
      if ((not_found_box.major_overlap(a_blob_box) || a_blob_box.major_overlap(not_found_box)) &&
          not_found_box.y_overlap_fraction(a_blob_box) > 0.8) {
        // Already taken care of.
        delete not_found_it.extract();
        break;
      }
    }
  }
  if (orphan_blobs) {
    C_BLOB_IT orphan_blobs_it(orphan_blobs);
    orphan_blobs_it.move_to_last();
    orphan_blobs_it.add_list_after(&not_found_blobs);
  }

  // New blobs are ready. Create a new werd object with these.
  WERD *new_werd = nullptr;
  if (!new_werd_blobs.empty()) {
    new_werd = new WERD(&new_werd_blobs, this);
  } else {
    // Add the blobs back to this word so that it can be reused.
    C_BLOB_IT this_list_it(cblob_list());
    this_list_it.add_list_after(&not_found_blobs);
  }
  return new_werd;
}