static void BM_SetInsert(benchmark::State& state) {
  std::set<int> data;
  for (auto _ : state) {
    state.PauseTiming();
    ConstructRandomSet(state.range(0), data );
    state.ResumeTiming();
    for (int j = 0; j < state.range(1); ++j)
      data.insert(random(0, state.range(1)));
  }
}