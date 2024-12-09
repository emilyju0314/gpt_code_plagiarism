static void BM_StringFindNoMatch(benchmark::State &state) {
  std::string s1(state.range(0), '-');
  std::string s2(8, '*');
  while (state.KeepRunning())
    benchmark::DoNotOptimize(s1.find(s2));
}