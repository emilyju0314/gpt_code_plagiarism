void Input::PreparePixInput(const StaticShape &shape, const Image pix, TRand *randomizer,
                            NetworkIO *input) {
  bool color = shape.depth() == 3;
  Image var_pix = pix;
  int depth = pixGetDepth(var_pix);
  Image normed_pix = nullptr;
  // On input to BaseAPI, an image is forced to be 1, 8 or 24 bit, without
  // colormap, so we just have to deal with depth conversion here.
  if (color) {
    // Force RGB.
    if (depth == 32) {
      normed_pix = var_pix.clone();
    } else {
      normed_pix = pixConvertTo32(var_pix);
    }
  } else {
    // Convert non-8-bit images to 8 bit.
    if (depth == 8) {
      normed_pix = var_pix.clone();
    } else {
      normed_pix = pixConvertTo8(var_pix, false);
    }
  }
  int height = pixGetHeight(normed_pix);
  int target_height = shape.height();
  if (target_height == 1) {
    target_height = shape.depth();
  }
  if (target_height != 0 && target_height != height) {
    // Get the scaled image.
    float im_factor = static_cast<float>(target_height) / height;
    Image scaled_pix = pixScale(normed_pix, im_factor, im_factor);
    normed_pix.destroy();
    normed_pix = scaled_pix;
  }
  input->FromPix(shape, normed_pix, randomizer);
  normed_pix.destroy();
}