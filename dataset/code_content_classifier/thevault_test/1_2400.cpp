double CSK_Interface::interpolate_cell_sigc(const int64_t cell, const double freq) const {
  // call the appropriate routine in the electron interp object (unscaled -- it'll be scaled in the
  // library)
  Require(llnli->pre_interped());
  return llnli->interpolate_sigc(cell, freq);
}