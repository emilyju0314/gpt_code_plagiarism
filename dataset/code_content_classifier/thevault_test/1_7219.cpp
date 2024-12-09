void fl_OleInitialize() {
  if (!oleInitialized) {
    OleInitialize(0L);
    oleInitialized = 1;
  }
}