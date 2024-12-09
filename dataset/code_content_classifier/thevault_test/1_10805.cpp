Image TrainingSample::RenderToPix(const UNICHARSET *unicharset) const {
  Image pix = pixCreate(kIntFeatureExtent, kIntFeatureExtent, 1);
  for (uint32_t f = 0; f < num_features_; ++f) {
    int start_x = features_[f].X;
    int start_y = kIntFeatureExtent - features_[f].Y;
    double dx = cos((features_[f].Theta / 256.0) * 2.0 * M_PI - M_PI);
    double dy = -sin((features_[f].Theta / 256.0) * 2.0 * M_PI - M_PI);
    for (int i = 0; i <= 5; ++i) {
      int x = static_cast<int>(start_x + dx * i);
      int y = static_cast<int>(start_y + dy * i);
      if (x >= 0 && x < 256 && y >= 0 && y < 256) {
        pixSetPixel(pix, x, y, 1);
      }
    }
  }
  if (unicharset != nullptr) {
    pixSetText(pix, unicharset->id_to_unichar(class_id_));
  }
  return pix;
}