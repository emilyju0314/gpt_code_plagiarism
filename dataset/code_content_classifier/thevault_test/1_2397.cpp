double CSK_Interface::interpolate_erec(const double Tm, const double freq) const {
  // call the appropriate routine in the electron interp object
  // (unscaled -- it'll be scaled in the library
  return llnli->interpolate_erec(Tm, freq);
}