void TrainingSample::DisplayFeatures(ScrollView::Color color, ScrollView *window) const {
  for (uint32_t f = 0; f < num_features_; ++f) {
    RenderIntFeature(window, &features_[f], color);
  }
}