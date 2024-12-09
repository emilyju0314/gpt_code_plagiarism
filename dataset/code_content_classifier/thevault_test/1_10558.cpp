int os_detect(TO_BLOCK_LIST *port_blocks, OSResults *osr, tesseract::Tesseract *tess) {
  int blobs_total = 0;
  TO_BLOCK_IT block_it;
  block_it.set_to_list(port_blocks);

  BLOBNBOX_CLIST filtered_list;
  BLOBNBOX_C_IT filtered_it(&filtered_list);

  for (block_it.mark_cycle_pt(); !block_it.cycled_list(); block_it.forward()) {
    TO_BLOCK *to_block = block_it.data();
    if (to_block->block->pdblk.poly_block() && !to_block->block->pdblk.poly_block()->IsText()) {
      continue;
    }
    BLOBNBOX_IT bbox_it;
    bbox_it.set_to_list(&to_block->blobs);
    for (bbox_it.mark_cycle_pt(); !bbox_it.cycled_list(); bbox_it.forward()) {
      BLOBNBOX *bbox = bbox_it.data();
      C_BLOB *blob = bbox->cblob();
      TBOX box = blob->bounding_box();
      ++blobs_total;

      // Catch illegal value of box width and avoid division by zero.
      if (box.width() == 0) {
        continue;
      }
      // TODO: Can height and width be negative? If not, remove fabs.
      float y_x = std::fabs((box.height() * 1.0f) / box.width());
      float x_y = 1.0f / y_x;
      // Select a >= 1.0 ratio
      float ratio = x_y > y_x ? x_y : y_x;
      // Blob is ambiguous
      if (ratio > kSizeRatioToReject) {
        continue;
      }
      if (box.height() < kMinAcceptableBlobHeight) {
        continue;
      }
      filtered_it.add_to_end(bbox);
    }
  }
  return os_detect_blobs(nullptr, &filtered_list, osr, tess);
}