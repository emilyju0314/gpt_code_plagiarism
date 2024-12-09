int Tesseract::SegmentPage(const char *input_file, BLOCK_LIST *blocks, Tesseract *osd_tess,
                           OSResults *osr) {
  ASSERT_HOST(pix_binary_ != nullptr);
  int width = pixGetWidth(pix_binary_);
  int height = pixGetHeight(pix_binary_);
  // Get page segmentation mode.
  auto pageseg_mode = static_cast<PageSegMode>(static_cast<int>(tessedit_pageseg_mode));
  // If a UNLV zone file can be found, use that instead of segmentation.
  if (!PSM_COL_FIND_ENABLED(pageseg_mode) && input_file != nullptr && input_file[0] != '\0') {
    std::string name = input_file;
    const char *lastdot = strrchr(name.c_str(), '.');
    if (lastdot != nullptr) {
      name[lastdot - name.c_str()] = '\0';
    }
    read_unlv_file(name, width, height, blocks);
  }
  if (blocks->empty()) {
    // No UNLV file present. Work according to the PageSegMode.
    // First make a single block covering the whole image.
    BLOCK_IT block_it(blocks);
    auto *block = new BLOCK("", true, 0, 0, 0, 0, width, height);
    block->set_right_to_left(right_to_left());
    block_it.add_to_end(block);
  } else {
    // UNLV file present. Use PSM_SINGLE_BLOCK.
    pageseg_mode = PSM_SINGLE_BLOCK;
  }
  // The diacritic_blobs holds noise blobs that may be diacritics. They
  // are separated out on areas of the image that seem noisy and short-circuit
  // the layout process, going straight from the initial partition creation
  // right through to after word segmentation, where they are added to the
  // rej_cblobs list of the most appropriate word. From there classification
  // will determine whether they are used.
  BLOBNBOX_LIST diacritic_blobs;
  int auto_page_seg_ret_val = 0;
  TO_BLOCK_LIST to_blocks;
  if (PSM_OSD_ENABLED(pageseg_mode) || PSM_BLOCK_FIND_ENABLED(pageseg_mode) ||
      PSM_SPARSE(pageseg_mode)) {
    auto_page_seg_ret_val =
        AutoPageSeg(pageseg_mode, blocks, &to_blocks,
                    enable_noise_removal ? &diacritic_blobs : nullptr, osd_tess, osr);
    if (pageseg_mode == PSM_OSD_ONLY) {
      return auto_page_seg_ret_val;
    }
    // To create blobs from the image region bounds uncomment this line:
    //  to_blocks.clear();  // Uncomment to go back to the old mode.
  } else {
    deskew_ = FCOORD(1.0f, 0.0f);
    reskew_ = FCOORD(1.0f, 0.0f);
    if (pageseg_mode == PSM_CIRCLE_WORD) {
      Image pixcleaned = RemoveEnclosingCircle(pix_binary_);
      if (pixcleaned != nullptr) {
        pix_binary_.destroy();
        pix_binary_ = pixcleaned;
      }
    }
  }

  if (auto_page_seg_ret_val < 0) {
    return -1;
  }

  if (blocks->empty()) {
    if (textord_debug_tabfind) {
      tprintf("Empty page\n");
    }
    return 0; // AutoPageSeg found an empty page.
  }
  bool splitting = pageseg_devanagari_split_strategy != ShiroRekhaSplitter::NO_SPLIT;
  bool cjk_mode = textord_use_cjk_fp_model;

  textord_.TextordPage(pageseg_mode, reskew_, width, height, pix_binary_, pix_thresholds_,
                       pix_grey_, splitting || cjk_mode, &diacritic_blobs, blocks, &to_blocks);
  return auto_page_seg_ret_val;
}