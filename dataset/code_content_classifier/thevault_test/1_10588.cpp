Image ImageFind::FindImages(Image pix, DebugPixa *pixa_debug) {
  // Not worth looking at small images.
  if (pixGetWidth(pix) < kMinImageFindSize || pixGetHeight(pix) < kMinImageFindSize) {
    return pixCreate(pixGetWidth(pix), pixGetHeight(pix), 1);
  }

  // Reduce by factor 2.
  Image pixr = pixReduceRankBinaryCascade(pix, 1, 0, 0, 0);
  if (textord_tabfind_show_images && pixa_debug != nullptr) {
    pixa_debug->AddPix(pixr, "CascadeReduced");
  }

  // Get the halftone mask directly from Leptonica.
  //
  // Leptonica will print an error message and return nullptr if we call
  // pixGenHalftoneMask(pixr, nullptr, ...) with too small image, so we
  // want to bypass that.
  if (pixGetWidth(pixr) < kMinImageFindSize || pixGetHeight(pixr) < kMinImageFindSize) {
    pixr.destroy();
    return pixCreate(pixGetWidth(pix), pixGetHeight(pix), 1);
  }
  // Get the halftone mask.
  l_int32 ht_found = 0;
  Pixa *pixadb = (textord_tabfind_show_images && pixa_debug != nullptr) ? pixaCreate(0) : nullptr;
  Image pixht2 = pixGenerateHalftoneMask(pixr, nullptr, &ht_found, pixadb);
  if (pixadb) {
    Image pixdb = pixaDisplayTiledInColumns(pixadb, 3, 1.0, 20, 2);
    if (textord_tabfind_show_images && pixa_debug != nullptr) {
      pixa_debug->AddPix(pixdb, "HalftoneMask");
    }
    pixdb.destroy();
    pixaDestroy(&pixadb);
  }
  pixr.destroy();
  if (!ht_found && pixht2 != nullptr) {
    pixht2.destroy();
  }
  if (pixht2 == nullptr) {
    return pixCreate(pixGetWidth(pix), pixGetHeight(pix), 1);
  }

  // Expand back up again.
  Image pixht = pixExpandReplicate(pixht2, 2);
  if (textord_tabfind_show_images && pixa_debug != nullptr) {
    pixa_debug->AddPix(pixht, "HalftoneReplicated");
  }
  pixht2.destroy();

  // Fill to capture pixels near the mask edges that were missed
  Image pixt = pixSeedfillBinary(nullptr, pixht, pix, 8);
  pixht |= pixt;
  pixt.destroy();

  // Eliminate lines and bars that may be joined to images.
  Image pixfinemask = pixReduceRankBinaryCascade(pixht, 1, 1, 3, 3);
  pixDilateBrick(pixfinemask, pixfinemask, 5, 5);
  if (textord_tabfind_show_images && pixa_debug != nullptr) {
    pixa_debug->AddPix(pixfinemask, "FineMask");
  }
  Image pixreduced = pixReduceRankBinaryCascade(pixht, 1, 1, 1, 1);
  Image pixreduced2 = pixReduceRankBinaryCascade(pixreduced, 3, 3, 3, 0);
  pixreduced.destroy();
  pixDilateBrick(pixreduced2, pixreduced2, 5, 5);
  Image pixcoarsemask = pixExpandReplicate(pixreduced2, 8);
  pixreduced2.destroy();
  if (textord_tabfind_show_images && pixa_debug != nullptr) {
    pixa_debug->AddPix(pixcoarsemask, "CoarseMask");
  }
  // Combine the coarse and fine image masks.
  pixcoarsemask &= pixfinemask;
  pixfinemask.destroy();
  // Dilate a bit to make sure we get everything.
  pixDilateBrick(pixcoarsemask, pixcoarsemask, 3, 3);
  Image pixmask = pixExpandReplicate(pixcoarsemask, 16);
  pixcoarsemask.destroy();
  if (textord_tabfind_show_images && pixa_debug != nullptr) {
    pixa_debug->AddPix(pixmask, "MaskDilated");
  }
  // And the image mask with the line and bar remover.
  pixht &= pixmask;
  pixmask.destroy();
  if (textord_tabfind_show_images && pixa_debug != nullptr) {
    pixa_debug->AddPix(pixht, "FinalMask");
  }
  // Make the result image the same size as the input.
  Image result = pixCreate(pixGetWidth(pix), pixGetHeight(pix), 1);
  result |= pixht;
  pixht.destroy();
  return result;
}