bool BoxChar::ContainsMostlyRTL(const std::vector<BoxChar *> &boxes) {
  int num_rtl = 0, num_ltr = 0;
  for (auto boxe : boxes) {
    boxe->GetDirection(&num_rtl, &num_ltr);
  }
  return num_rtl > num_ltr;
}