int Tesseract::AutoPageSeg(PageSegMode pageseg_mode, BLOCK_LIST *blocks, TO_BLOCK_LIST *to_blocks,
                           BLOBNBOX_LIST *diacritic_blobs, Tesseract *osd_tess, OSResults *osr) {
  Image photomask_pix = nullptr;
  Image musicmask_pix = nullptr;
  // The blocks made by the ColumnFinder. Moved to blocks before return.
  BLOCK_LIST found_blocks;
  TO_BLOCK_LIST temp_blocks;

  ColumnFinder *finder = SetupPageSegAndDetectOrientation(
      pageseg_mode, blocks, osd_tess, osr, &temp_blocks, &photomask_pix,
      pageseg_apply_music_mask ? &musicmask_pix : nullptr);
  int result = 0;
  if (finder != nullptr) {
    TO_BLOCK_IT to_block_it(&temp_blocks);
    TO_BLOCK *to_block = to_block_it.data();
    if (musicmask_pix != nullptr) {
      // TODO(rays) pass the musicmask_pix into FindBlocks and mark music
      // blocks separately. For now combine with photomask_pix.
      photomask_pix |= musicmask_pix;
    }
#ifndef DISABLED_LEGACY_ENGINE
    if (equ_detect_) {
      finder->SetEquationDetect(equ_detect_);
    }
#endif // ndef DISABLED_LEGACY_ENGINE
    result = finder->FindBlocks(pageseg_mode, scaled_color_, scaled_factor_, to_block,
                                photomask_pix, pix_thresholds_, pix_grey_, &pixa_debug_,
                                &found_blocks, diacritic_blobs, to_blocks);
    if (result >= 0) {
      finder->GetDeskewVectors(&deskew_, &reskew_);
    }
    delete finder;
  }
  photomask_pix.destroy();
  musicmask_pix.destroy();
  if (result < 0) {
    return result;
  }

  blocks->clear();
  BLOCK_IT block_it(blocks);
  // Move the found blocks to the input/output blocks.
  block_it.add_list_after(&found_blocks);
  return result;
}