int ProjectiveCoeffs(int width, int height, TRand *randomizer, float **im_coeffs,
                     float **box_coeffs) {
  // Setup "from" points.
  Pta *src_pts = ptaCreate(4);
  ptaAddPt(src_pts, 0.0f, 0.0f);
  ptaAddPt(src_pts, width, 0.0f);
  ptaAddPt(src_pts, width, height);
  ptaAddPt(src_pts, 0.0f, height);
  // Extract factors from pseudo-random sequence.
  float factors[FN_NUM_FACTORS];
  float shear = 0.0f; // Shear is signed.
  for (int i = 0; i < FN_NUM_FACTORS; ++i) {
    // Everything is squared to make wild values rarer.
    if (i == FN_SHEAR) {
      // Shear is signed.
      shear = randomizer->SignedRand(0.5 / 3.0);
      shear = shear >= 0.0 ? shear * shear : -shear * shear;
      // Keep the sheared points within the original rectangle.
      if (shear < -factors[FN_X0]) {
        shear = -factors[FN_X0];
      }
      if (shear > factors[FN_X1]) {
        shear = factors[FN_X1];
      }
      factors[i] = shear;
    } else if (i != FN_INCOLOR) {
      factors[i] = fabs(randomizer->SignedRand(1.0));
      if (i <= FN_Y3) {
        factors[i] *= 5.0 / 8.0;
      } else {
        factors[i] *= 0.5;
      }
      factors[i] *= factors[i];
    }
  }
  // Setup "to" points.
  Pta *dest_pts = ptaCreate(4);
  ptaAddPt(dest_pts, factors[FN_X0] * width, factors[FN_Y0] * height);
  ptaAddPt(dest_pts, (1.0f - factors[FN_X1]) * width, factors[FN_Y1] * height);
  ptaAddPt(dest_pts, (1.0f - factors[FN_X1] + shear) * width, (1 - factors[FN_Y2]) * height);
  ptaAddPt(dest_pts, (factors[FN_X0] + shear) * width, (1 - factors[FN_Y3]) * height);
  getProjectiveXformCoeffs(dest_pts, src_pts, im_coeffs);
  getProjectiveXformCoeffs(src_pts, dest_pts, box_coeffs);
  ptaDestroy(&src_pts);
  ptaDestroy(&dest_pts);
  return factors[FN_INCOLOR] > 0.5f ? L_BRING_IN_WHITE : L_BRING_IN_BLACK;
}