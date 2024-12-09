Image PrepareDistortedPix(const Image pix, bool perspective, bool invert, bool white_noise,
                         bool smooth_noise, bool blur, int box_reduction, TRand *randomizer,
                         std::vector<TBOX> *boxes) {
  Image distorted = pix.copy();
  // Things to do to synthetic training data.
  if ((white_noise || smooth_noise) && randomizer->SignedRand(1.0) > 0.0) {
    // TODO(rays) Cook noise in a more thread-safe manner than rand().
    // Attempt to make the sequences reproducible.
    srand(randomizer->IntRand());
    Image pixn = pixAddGaussianNoise(distorted, 8.0);
    distorted.destroy();
    if (smooth_noise) {
      distorted = pixBlockconv(pixn, 1, 1);
      pixn.destroy();
    } else {
      distorted = pixn;
    }
  }
  if (blur && randomizer->SignedRand(1.0) > 0.0) {
    Image blurred = pixBlockconv(distorted, 1, 1);
    distorted.destroy();
    distorted = blurred;
  }
  if (perspective) {
    GeneratePerspectiveDistortion(0, 0, randomizer, &distorted, boxes);
  }
  if (boxes != nullptr) {
    for (auto &b : *boxes) {
      b.scale(1.0f / box_reduction);
      if (b.width() <= 0) {
        b.set_right(b.left() + 1);
      }
    }
  }
  if (invert && randomizer->SignedRand(1.0) < -0) {
    pixInvert(distorted, distorted);
  }
  return distorted;
}