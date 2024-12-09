Image DegradeImage(Image input, int exposure, TRand *randomizer, float *rotation) {
  Image pix = pixConvertTo8(input, false);
  input.destroy();
  input = pix;
  int width = pixGetWidth(input);
  int height = pixGetHeight(input);

  if (exposure >= 2) {
    // An erosion simulates the spreading darkening of a dark copy.
    // This is backwards to binary morphology,
    // see http://www.leptonica.com/grayscale-morphology.html
    pix = input;
    input = pixErodeGray(pix, 3, 3);
    pix.destroy();
  }
  // A convolution is essential to any mode as no scanner produces an
  // image as sharp as the electronic image.
  pix = pixBlockconv(input, 1, 1);
  input.destroy();
  // A small random rotation helps to make the edges jaggy in a realistic way.
  if (rotation != nullptr) {
    float radians_clockwise = 0.0f;
    if (*rotation) {
      radians_clockwise = *rotation;
    } else if (randomizer != nullptr) {
      radians_clockwise = randomizer->SignedRand(kRotationRange);
    }

    input = pixRotate(pix, radians_clockwise, L_ROTATE_AREA_MAP, L_BRING_IN_WHITE, 0, 0);
    // Rotate the boxes to match.
    *rotation = radians_clockwise;
    pix.destroy();
  } else {
    input = pix;
  }

  if (exposure >= 3 || exposure == 1) {
    // Erosion after the convolution is not as heavy as before, so it is
    // good for level 1 and in addition as a level 3.
    // This is backwards to binary morphology,
    // see http://www.leptonica.com/grayscale-morphology.html
    pix = input;
    input = pixErodeGray(pix, 3, 3);
    pix.destroy();
  }
  // The convolution really needed to be 2x2 to be realistic enough, but
  // we only have 3x3, so we have to bias the image darker or lose thin
  // strokes.
  int erosion_offset = 0;
  // For light and 0 exposure, there is no dilation, so compensate for the
  // convolution with a big darkening bias which is undone for lighter
  // exposures.
  if (exposure <= 0) {
    erosion_offset = -3 * kExposureFactor;
  }
  // Add in a general offset of the greyscales for the exposure level so
  // a threshold of 128 gives a reasonable binary result.
  erosion_offset -= exposure * kExposureFactor;
  // Add a gradual fade over the page and a small amount of salt and pepper
  // noise to simulate noise in the sensor/paper fibres and varying
  // illumination.
  l_uint32 *data = pixGetData(input);
  for (int y = 0; y < height; ++y) {
    for (int x = 0; x < width; ++x) {
      int pixel = GET_DATA_BYTE(data, x);
      if (randomizer != nullptr) {
        pixel += randomizer->IntRand() % (kSaltnPepper * 2 + 1) - kSaltnPepper;
      }
      if (height + width > kMinRampSize) {
        pixel -= (2 * x + y) * 32 / (height + width);
      }
      pixel += erosion_offset;
      if (pixel < 0) {
        pixel = 0;
      }
      if (pixel > 255) {
        pixel = 255;
      }
      SET_DATA_BYTE(data, x, pixel);
    }
    data += input->wpl;
  }
  return input;
}