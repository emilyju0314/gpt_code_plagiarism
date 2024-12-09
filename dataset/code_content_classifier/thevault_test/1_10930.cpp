void GeneratePerspectiveDistortion(int width, int height, TRand *randomizer, Image *pix,
                                   std::vector<TBOX> *boxes) {
  if (pix != nullptr && *pix != nullptr) {
    width = pixGetWidth(*pix);
    height = pixGetHeight(*pix);
  }
  float *im_coeffs = nullptr;
  float *box_coeffs = nullptr;
  l_int32 incolor = ProjectiveCoeffs(width, height, randomizer, &im_coeffs, &box_coeffs);
  if (pix != nullptr && *pix != nullptr) {
    // Transform the image.
    Image transformed = pixProjective(*pix, im_coeffs, incolor);
    if (transformed == nullptr) {
      tprintf("Projective transformation failed!!\n");
      return;
    }
    pix->destroy();
    *pix = transformed;
  }
  if (boxes != nullptr) {
    // Transform the boxes.
    for (auto &b : *boxes) {
      int x1, y1, x2, y2;
      const TBOX &box = b;
      projectiveXformSampledPt(box_coeffs, box.left(), height - box.top(), &x1, &y1);
      projectiveXformSampledPt(box_coeffs, box.right(), height - box.bottom(), &x2, &y2);
      TBOX new_box1(x1, height - y2, x2, height - y1);
      projectiveXformSampledPt(box_coeffs, box.left(), height - box.bottom(), &x1, &y1);
      projectiveXformSampledPt(box_coeffs, box.right(), height - box.top(), &x2, &y2);
      TBOX new_box2(x1, height - y1, x2, height - y2);
      b = new_box1.bounding_union(new_box2);
    }
  }
  lept_free(im_coeffs);
  lept_free(box_coeffs);
}