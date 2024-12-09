void Network::DisplayForward(const NetworkIO &matrix) {
  Image image = matrix.ToPix();
  ClearWindow(false, name_.c_str(), pixGetWidth(image), pixGetHeight(image), &forward_win_);
  DisplayImage(image, forward_win_);
  forward_win_->Update();
}