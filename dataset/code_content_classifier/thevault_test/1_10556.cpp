static void remove_nontext_regions(tesseract::Tesseract *tess, BLOCK_LIST *blocks,
                                   TO_BLOCK_LIST *to_blocks) {
  Image pix = tess->pix_binary();
  ASSERT_HOST(pix != nullptr);
  int vertical_x = 0;
  int vertical_y = 1;
  tesseract::TabVector_LIST v_lines;
  tesseract::TabVector_LIST h_lines;
  int resolution;
  if (kMinCredibleResolution > pixGetXRes(pix)) {
    resolution = kMinCredibleResolution;
    tprintf("Warning. Invalid resolution %d dpi. Using %d instead.\n", pixGetXRes(pix), resolution);
  } else {
    resolution = pixGetXRes(pix);
  }

  tesseract::LineFinder::FindAndRemoveLines(resolution, false, pix, &vertical_x, &vertical_y,
                                            nullptr, &v_lines, &h_lines);
  Image im_pix = tesseract::ImageFind::FindImages(pix, nullptr);
  if (im_pix != nullptr) {
    pixSubtract(pix, pix, im_pix);
    im_pix.destroy();
  }
  tess->mutable_textord()->find_components(tess->pix_binary(), blocks, to_blocks);
}