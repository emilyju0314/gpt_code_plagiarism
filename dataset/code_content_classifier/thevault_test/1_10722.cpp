ColumnFinder *Tesseract::SetupPageSegAndDetectOrientation(PageSegMode pageseg_mode,
                                                          BLOCK_LIST *blocks, Tesseract *osd_tess,
                                                          OSResults *osr, TO_BLOCK_LIST *to_blocks,
                                                          Image *photo_mask_pix,
                                                          Image *music_mask_pix) {
  int vertical_x = 0;
  int vertical_y = 1;
  TabVector_LIST v_lines;
  TabVector_LIST h_lines;
  ICOORD bleft(0, 0);

  ASSERT_HOST(pix_binary_ != nullptr);
  if (tessedit_dump_pageseg_images) {
    pixa_debug_.AddPix(pix_binary_, "PageSegInput");
  }
  // Leptonica is used to find the rule/separator lines in the input.
  LineFinder::FindAndRemoveLines(source_resolution_, textord_tabfind_show_vlines, pix_binary_,
                                 &vertical_x, &vertical_y, music_mask_pix, &v_lines, &h_lines);
  if (tessedit_dump_pageseg_images) {
    pixa_debug_.AddPix(pix_binary_, "NoLines");
  }
  // Leptonica is used to find a mask of the photo regions in the input.
  *photo_mask_pix = ImageFind::FindImages(pix_binary_, &pixa_debug_);
  if (tessedit_dump_pageseg_images) {
    Image pix_no_image_ = nullptr;
    if (*photo_mask_pix != nullptr) {
      pix_no_image_ = pixSubtract(nullptr, pix_binary_, *photo_mask_pix);
    } else {
      pix_no_image_ = pix_binary_.clone();
    }
    pixa_debug_.AddPix(pix_no_image_, "NoImages");
    pix_no_image_.destroy();
  }
  if (!PSM_COL_FIND_ENABLED(pageseg_mode)) {
    v_lines.clear();
  }

  // The rest of the algorithm uses the usual connected components.
  textord_.find_components(pix_binary_, blocks, to_blocks);

  TO_BLOCK_IT to_block_it(to_blocks);
  // There must be exactly one input block.
  // TODO(rays) handle new textline finding with a UNLV zone file.
  ASSERT_HOST(to_blocks->singleton());
  TO_BLOCK *to_block = to_block_it.data();
  TBOX blkbox = to_block->block->pdblk.bounding_box();
  ColumnFinder *finder = nullptr;
  int estimated_resolution = source_resolution_;
  if (source_resolution_ == kMinCredibleResolution) {
    // Try to estimate resolution from typical body text size.
    int res = IntCastRounded(to_block->line_size * kResolutionEstimationFactor);
    if (res > estimated_resolution && res < kMaxCredibleResolution) {
      estimated_resolution = res;
      tprintf("Estimating resolution as %d\n", estimated_resolution);
    }
  }

  if (to_block->line_size >= 2) {
    finder = new ColumnFinder(static_cast<int>(to_block->line_size), blkbox.botleft(),
                              blkbox.topright(), estimated_resolution, textord_use_cjk_fp_model,
                              textord_tabfind_aligned_gap_fraction, &v_lines, &h_lines, vertical_x,
                              vertical_y);

    finder->SetupAndFilterNoise(pageseg_mode, *photo_mask_pix, to_block);

#ifndef DISABLED_LEGACY_ENGINE

    if (equ_detect_) {
      equ_detect_->LabelSpecialText(to_block);
    }

    BLOBNBOX_CLIST osd_blobs;
    // osd_orientation is the number of 90 degree rotations to make the
    // characters upright. (See tesseract/osdetect.h for precise definition.)
    // We want the text lines horizontal, (vertical text indicates vertical
    // textlines) which may conflict (eg vertically written CJK).
    int osd_orientation = 0;
    bool vertical_text =
        textord_tabfind_force_vertical_text || pageseg_mode == PSM_SINGLE_BLOCK_VERT_TEXT;
    if (!vertical_text && textord_tabfind_vertical_text && PSM_ORIENTATION_ENABLED(pageseg_mode)) {
      vertical_text = finder->IsVerticallyAlignedText(textord_tabfind_vertical_text_ratio, to_block,
                                                      &osd_blobs);
    }
    if (PSM_OSD_ENABLED(pageseg_mode) && osd_tess != nullptr && osr != nullptr) {
      std::vector<int> osd_scripts;
      if (osd_tess != this) {
        // We are running osd as part of layout analysis, so constrain the
        // scripts to those allowed by *this.
        AddAllScriptsConverted(unicharset, osd_tess->unicharset, &osd_scripts);
        for (auto &lang : sub_langs_) {
          AddAllScriptsConverted(lang->unicharset, osd_tess->unicharset, &osd_scripts);
        }
      }
      os_detect_blobs(&osd_scripts, &osd_blobs, osr, osd_tess);
      if (pageseg_mode == PSM_OSD_ONLY) {
        delete finder;
        return nullptr;
      }
      osd_orientation = osr->best_result.orientation_id;
      double osd_score = osr->orientations[osd_orientation];
      double osd_margin = min_orientation_margin * 2;
      for (int i = 0; i < 4; ++i) {
        if (i != osd_orientation && osd_score - osr->orientations[i] < osd_margin) {
          osd_margin = osd_score - osr->orientations[i];
        }
      }
      int best_script_id = osr->best_result.script_id;
      const char *best_script_str = osd_tess->unicharset.get_script_from_script_id(best_script_id);
      bool cjk = best_script_id == osd_tess->unicharset.han_sid() ||
                 best_script_id == osd_tess->unicharset.hiragana_sid() ||
                 best_script_id == osd_tess->unicharset.katakana_sid() ||
                 strcmp("Japanese", best_script_str) == 0 ||
                 strcmp("Korean", best_script_str) == 0 || strcmp("Hangul", best_script_str) == 0;
      if (cjk) {
        finder->set_cjk_script(true);
      }
      if (osd_margin < min_orientation_margin) {
        // The margin is weak.
        if (!cjk && !vertical_text && osd_orientation == 2) {
          // upside down latin text is improbable with such a weak margin.
          tprintf(
              "OSD: Weak margin (%.2f), horiz textlines, not CJK: "
              "Don't rotate.\n",
              osd_margin);
          osd_orientation = 0;
        } else {
          tprintf(
              "OSD: Weak margin (%.2f) for %d blob text block, "
              "but using orientation anyway: %d\n",
              osd_margin, osd_blobs.length(), osd_orientation);
        }
      }
    }
    osd_blobs.shallow_clear();
    finder->CorrectOrientation(to_block, vertical_text, osd_orientation);

#endif // ndef DISABLED_LEGACY_ENGINE
  }

  return finder;
}