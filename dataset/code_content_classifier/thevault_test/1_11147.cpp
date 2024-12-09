void clear_fx_win() { // make features win
  fx_win->Clear();
  fx_win->Pen(64, 64, 64);
  fx_win->Line(-WERDWIDTH, kBlnBaselineOffset, WERDWIDTH, kBlnBaselineOffset);
  fx_win->Line(-WERDWIDTH, kBlnXHeight + kBlnBaselineOffset, WERDWIDTH,
               kBlnXHeight + kBlnBaselineOffset);
}