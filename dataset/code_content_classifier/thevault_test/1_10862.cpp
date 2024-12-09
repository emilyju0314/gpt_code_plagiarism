bool Input::Backward(bool debug, const NetworkIO &fwd_deltas, NetworkScratch *scratch,
                     NetworkIO *back_deltas) {
  tprintf("Input::Backward should not be called!!\n");
  return false;
}