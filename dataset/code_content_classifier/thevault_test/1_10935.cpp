void Textord::TextordPage(PageSegMode pageseg_mode, const FCOORD &reskew, int width, int height,
                          Image binary_pix, Image thresholds_pix, Image grey_pix, bool use_box_bottoms,
                          BLOBNBOX_LIST *diacritic_blobs, BLOCK_LIST *blocks,
                          TO_BLOCK_LIST *to_blocks) {
  page_tr_.set_x(width);
  page_tr_.set_y(height);
  if (to_blocks->empty()) {
    // AutoPageSeg was not used, so we need to find_components first.
    find_components(binary_pix, blocks, to_blocks);
    TO_BLOCK_IT it(to_blocks);
    for (it.mark_cycle_pt(); !it.cycled_list(); it.forward()) {
      TO_BLOCK *to_block = it.data();
      // Compute the edge offsets whether or not there is a grey_pix.
      // We have by-passed auto page seg, so we have to run it here.
      // By page segmentation mode there is no non-text to avoid running on.
      to_block->ComputeEdgeOffsets(thresholds_pix, grey_pix);
    }
  } else if (!PSM_SPARSE(pageseg_mode)) {
    // AutoPageSeg does not need to find_components as it did that already.
    // Filter_blobs sets up the TO_BLOCKs the same as find_components does.
    filter_blobs(page_tr_, to_blocks, true);
  }

  ASSERT_HOST(!to_blocks->empty());
  if (pageseg_mode == PSM_SINGLE_BLOCK_VERT_TEXT) {
    const FCOORD anticlockwise90(0.0f, 1.0f);
    const FCOORD clockwise90(0.0f, -1.0f);
    TO_BLOCK_IT it(to_blocks);
    for (it.mark_cycle_pt(); !it.cycled_list(); it.forward()) {
      TO_BLOCK *to_block = it.data();
      BLOCK *block = to_block->block;
      // Create a fake poly_block in block from its bounding box.
      block->pdblk.set_poly_block(new POLY_BLOCK(block->pdblk.bounding_box(), PT_VERTICAL_TEXT));
      // Rotate the to_block along with its contained block and blobnbox lists.
      to_block->rotate(anticlockwise90);
      // Set the block's rotation values to obey the convention followed in
      // layout analysis for vertical text.
      block->set_re_rotation(clockwise90);
      block->set_classify_rotation(clockwise90);
    }
  }

  TO_BLOCK_IT to_block_it(to_blocks);
  TO_BLOCK *to_block = to_block_it.data();
  // Make the rows in the block.
  float gradient;
  // Do it the old fashioned way.
  if (PSM_LINE_FIND_ENABLED(pageseg_mode)) {
    gradient = make_rows(page_tr_, to_blocks);
  } else if (!PSM_SPARSE(pageseg_mode)) {
    // RAW_LINE, SINGLE_LINE, SINGLE_WORD and SINGLE_CHAR all need a single row.
    gradient = make_single_row(page_tr_, pageseg_mode != PSM_RAW_LINE, to_block, to_blocks);
  } else {
    gradient = 0.0f;
  }
  BaselineDetect baseline_detector(textord_baseline_debug, reskew, to_blocks);
  baseline_detector.ComputeStraightBaselines(use_box_bottoms);
  baseline_detector.ComputeBaselineSplinesAndXheights(
      page_tr_, pageseg_mode != PSM_RAW_LINE, textord_heavy_nr, textord_show_final_rows, this);
  // Now make the words in the lines.
  if (PSM_WORD_FIND_ENABLED(pageseg_mode)) {
    // SINGLE_LINE uses the old word maker on the single line.
    make_words(this, page_tr_, gradient, blocks, to_blocks);
  } else {
    // SINGLE_WORD and SINGLE_CHAR cram all the blobs into a
    // single word, and in SINGLE_CHAR mode, all the outlines
    // go in a single blob.
    TO_BLOCK *to_block = to_block_it.data();
    make_single_word(pageseg_mode == PSM_SINGLE_CHAR, to_block->get_rows(),
                     to_block->block->row_list());
  }
  // Remove empties.
  cleanup_blocks(PSM_WORD_FIND_ENABLED(pageseg_mode), blocks);
  TransferDiacriticsToBlockGroups(diacritic_blobs, blocks);
  // Compute the margins for each row in the block, to be used later for
  // paragraph detection.
  BLOCK_IT b_it(blocks);
  for (b_it.mark_cycle_pt(); !b_it.cycled_list(); b_it.forward()) {
    b_it.data()->compute_row_margins();
  }
#ifndef GRAPHICS_DISABLED
  close_to_win();
#endif
}