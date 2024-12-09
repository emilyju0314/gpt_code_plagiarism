void BlobGrid::InsertBlobList(BLOBNBOX_LIST *blobs) {
  BLOBNBOX_IT blob_it(blobs);
  for (blob_it.mark_cycle_pt(); !blob_it.cycled_list(); blob_it.forward()) {
    BLOBNBOX *blob = blob_it.data();
    if (!blob->joined_to_prev()) {
      InsertBBox(true, true, blob);
    }
  }
}