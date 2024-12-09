void IndexMapBiDi::InitAndSetupRange(int sparse_size, int start, int end) {
  Init(sparse_size, false);
  for (int i = start; i < end; ++i) {
    SetMap(i, true);
  }
  Setup();
}