void LSTM::PrintDW() {
  tprintf("Delta state:%s\n", name_.c_str());
  for (int w = 0; w < WT_COUNT; ++w) {
    if (w == GFS && !Is2D()) {
      continue;
    }
    tprintf("Gate %d, inputs\n", w);
    for (int i = 0; i < ni_; ++i) {
      tprintf("Row %d:", i);
      for (int s = 0; s < ns_; ++s) {
        tprintf(" %g", gate_weights_[w].GetDW(s, i));
      }
      tprintf("\n");
    }
    tprintf("Gate %d, outputs\n", w);
    for (int i = ni_; i < ni_ + ns_; ++i) {
      tprintf("Row %d:", i - ni_);
      for (int s = 0; s < ns_; ++s) {
        tprintf(" %g", gate_weights_[w].GetDW(s, i));
      }
      tprintf("\n");
    }
    tprintf("Gate %d, bias\n", w);
    for (int s = 0; s < ns_; ++s) {
      tprintf(" %g", gate_weights_[w].GetDW(s, na_));
    }
    tprintf("\n");
  }
}