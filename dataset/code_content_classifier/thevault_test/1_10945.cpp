void Series::AppendSeries(Network *src) {
  ASSERT_HOST(src->type() == NT_SERIES);
  auto *src_series = static_cast<Series *>(src);
  for (auto &s : src_series->stack_) {
    AddToStack(s);
    s = nullptr;
  }
  delete src;
}