void QualityScaler::ReportFramerate(int framerate) {
  num_samples_ = static_cast<size_t>(
      kMeasureSeconds * (framerate < kMinFps ? kMinFps : framerate));
  framerate_ = framerate;
}