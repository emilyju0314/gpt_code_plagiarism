Image Input::PrepareLSTMInputs(const ImageData &image_data, const Network *network, int min_width,
                              TRand *randomizer, float *image_scale) {
  // Note that NumInputs() is defined as input image height.
  int target_height = network->NumInputs();
  int width, height;
  Image pix =
      image_data.PreScale(target_height, kMaxInputHeight, image_scale, &width, &height, nullptr);
  if (pix == nullptr) {
    tprintf("Bad pix from ImageData!\n");
    return nullptr;
  }
  if (width < min_width || height < min_width) {
    tprintf("Image too small to scale!! (%dx%d vs min width of %d)\n", width, height, min_width);
    pix.destroy();
    return nullptr;
  }
  return pix;
}