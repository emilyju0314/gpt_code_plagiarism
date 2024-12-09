TEST_F(TableFinderTest, SplitAndInsertFragmentedPartitionsBasicPass) {
  finder_->set_global_median_blob_width(3);
  finder_->set_global_median_xheight(10);

  TBOX part_box(10, 5, 100, 15);
  auto *all = new ColPartition(BRT_UNKNOWN, ICOORD(0, 1));
  all->set_type(PT_FLOWING_TEXT);
  all->set_blob_type(BRT_TEXT);
  all->set_flow(BTFT_CHAIN);
  all->set_left_margin(10);
  all->set_right_margin(100);
  TBOX blob_box = part_box;
  for (int i = 10; i <= 20; i += 5) {
    blob_box.set_left(i + 1);
    blob_box.set_right(i + 4);
    all->AddBox(new BLOBNBOX(C_BLOB::FakeBlob(blob_box)));
  }
  for (int i = 35; i <= 55; i += 5) {
    blob_box.set_left(i + 1);
    blob_box.set_right(i + 4);
    all->AddBox(new BLOBNBOX(C_BLOB::FakeBlob(blob_box)));
  }
  for (int i = 80; i <= 95; i += 5) {
    blob_box.set_left(i + 1);
    blob_box.set_right(i + 4);
    all->AddBox(new BLOBNBOX(C_BLOB::FakeBlob(blob_box)));
  }
  // TODO(nbeato): Ray's newer code...
  // all->ClaimBoxes();
  all->ComputeLimits();     // This is to make sure median iinfo is set.
  InsertTextPartition(all); // This is to delete blobs
  ColPartition *fragment_me = all->CopyButDontOwnBlobs();

  finder_->SplitAndInsertFragmentedTextPartition(fragment_me);
  finder_->ExpectPartition(TBOX(11, 5, 24, 15));
  finder_->ExpectPartition(TBOX(36, 5, 59, 15));
  finder_->ExpectPartition(TBOX(81, 5, 99, 15));
  finder_->ExpectPartitionCount(3);
}