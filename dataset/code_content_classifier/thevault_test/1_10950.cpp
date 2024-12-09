void Network::DisplayBackward(const NetworkIO &matrix) {
  Image image = matrix.ToPix();
  std::string window_name = name_ + "-back";
  ClearWindow(false, window_name.c_str(), pixGetWidth(image), pixGetHeight(image), &backward_win_);
  DisplayImage(image, backward_win_);
  backward_win_->Update();
}