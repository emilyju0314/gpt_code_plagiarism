bool NetworkBuilder::InitNetwork(int num_outputs, const char *network_spec, int append_index,
                                 int net_flags, float weight_range, TRand *randomizer,
                                 Network **network) {
  NetworkBuilder builder(num_outputs);
  Series *bottom_series = nullptr;
  StaticShape input_shape;
  if (append_index >= 0) {
    // Split the current network after the given append_index.
    ASSERT_HOST(*network != nullptr && (*network)->type() == NT_SERIES);
    auto *series = static_cast<Series *>(*network);
    Series *top_series = nullptr;
    series->SplitAt(append_index, &bottom_series, &top_series);
    if (bottom_series == nullptr || top_series == nullptr) {
      tprintf("Yikes! Splitting current network failed!!\n");
      return false;
    }
    input_shape = bottom_series->OutputShape(input_shape);
    delete top_series;
  }
  *network = builder.BuildFromString(input_shape, &network_spec);
  if (*network == nullptr) {
    return false;
  }
  (*network)->SetNetworkFlags(net_flags);
  (*network)->InitWeights(weight_range, randomizer);
  (*network)->SetupNeedsBackprop(false);
  if (bottom_series != nullptr) {
    bottom_series->AppendSeries(*network);
    *network = bottom_series;
  }
  (*network)->CacheXScaleFactor((*network)->XScaleFactor());
  return true;
}