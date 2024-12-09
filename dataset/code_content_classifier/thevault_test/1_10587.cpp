static void ConnCompAndRectangularize(Image pix, DebugPixa *pixa_debug, Boxa **boxa,
                                      Pixa **pixa) {
  *boxa = nullptr;
  *pixa = nullptr;

  if (textord_tabfind_show_images && pixa_debug != nullptr) {
    pixa_debug->AddPix(pix, "Conncompimage");
  }
  // Find the individual image regions in the mask image.
  *boxa = pixConnComp(pix, pixa, 8);
  // Rectangularize the individual images. If a sharp edge in vertical and/or
  // horizontal occupancy can be found, it indicates a probably rectangular
  // image with unwanted bits merged on, so clip to the approximate rectangle.
  int npixes = 0;
  if (*boxa != nullptr && *pixa != nullptr) {
    npixes = pixaGetCount(*pixa);
  }
  for (int i = 0; i < npixes; ++i) {
    int x_start, x_end, y_start, y_end;
    Image img_pix = pixaGetPix(*pixa, i, L_CLONE);
    if (textord_tabfind_show_images && pixa_debug != nullptr) {
      pixa_debug->AddPix(img_pix, "A component");
    }
    if (pixNearlyRectangular(img_pix, kMinRectangularFraction, kMaxRectangularFraction,
                             kMaxRectangularGradient, &x_start, &y_start, &x_end, &y_end)) {
      Image simple_pix = pixCreate(x_end - x_start, y_end - y_start, 1);
      pixSetAll(simple_pix);
      img_pix.destroy();
      // pixaReplacePix takes ownership of the simple_pix.
      pixaReplacePix(*pixa, i, simple_pix, nullptr);
      img_pix = pixaGetPix(*pixa, i, L_CLONE);
      // Fix the box to match the new pix.
      l_int32 x, y, width, height;
      boxaGetBoxGeometry(*boxa, i, &x, &y, &width, &height);
      Box *simple_box = boxCreate(x + x_start, y + y_start, x_end - x_start, y_end - y_start);
      boxaReplaceBox(*boxa, i, simple_box);
    }
    img_pix.destroy();
  }
}