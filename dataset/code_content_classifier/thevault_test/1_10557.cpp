int orientation_and_script_detection(const char *filename, OSResults *osr,
                                     tesseract::Tesseract *tess) {
  std::string name = filename; // truncated name

  const char *lastdot = strrchr(name.c_str(), '.');
  if (lastdot != nullptr) {
    name[lastdot - name.c_str()] = '\0';
  }

  ASSERT_HOST(tess->pix_binary() != nullptr);
  int width = pixGetWidth(tess->pix_binary());
  int height = pixGetHeight(tess->pix_binary());

  BLOCK_LIST blocks;
  if (!read_unlv_file(name, width, height, &blocks)) {
    FullPageBlock(width, height, &blocks);
  }

  // Try to remove non-text regions from consideration.
  TO_BLOCK_LIST land_blocks, port_blocks;
  remove_nontext_regions(tess, &blocks, &port_blocks);

  if (port_blocks.empty()) {
    // page segmentation did not succeed, so we need to find_components first.
    tess->mutable_textord()->find_components(tess->pix_binary(), &blocks, &port_blocks);
  } else {
    TBOX page_box(0, 0, width, height);
    // Filter_blobs sets up the TO_BLOCKs the same as find_components does.
    tess->mutable_textord()->filter_blobs(page_box.topright(), &port_blocks, true);
  }

  return os_detect(&port_blocks, osr, tess);
}