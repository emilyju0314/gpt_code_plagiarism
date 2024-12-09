static Image RemoveEnclosingCircle(Image pixs) {
  Image pixsi = pixInvert(nullptr, pixs);
  Image pixc = pixCreateTemplate(pixs);
  pixSetOrClearBorder(pixc, 1, 1, 1, 1, PIX_SET);
  pixSeedfillBinary(pixc, pixc, pixsi, 4);
  pixInvert(pixc, pixc);
  pixsi.destroy();
  Image pixt = pixs & pixc;
  l_int32 max_count;
  pixCountConnComp(pixt, 8, &max_count);
  // The count has to go up before we start looking for the minimum.
  l_int32 min_count = INT32_MAX;
  Image pixout = nullptr;
  for (int i = 1; i < kMaxCircleErosions; i++) {
    pixt.destroy();
    pixErodeBrick(pixc, pixc, 3, 3);
    pixt = pixs & pixc;
    l_int32 count;
    pixCountConnComp(pixt, 8, &count);
    if (i == 1 || count > max_count) {
      max_count = count;
      min_count = count;
    } else if (count < min_count) {
      min_count = count;
      pixout.destroy();
      pixout = pixt.copy(); // Save the best.
    } else if (count >= min_count) {
      break; // We have passed by the best.
    }
  }
  pixt.destroy();
  pixc.destroy();
  return pixout;
}