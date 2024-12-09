void fl_OleUninitialize() {
  if (oleInitialized) {
    OleUninitialize();
    oleInitialized = 0;
  }
}