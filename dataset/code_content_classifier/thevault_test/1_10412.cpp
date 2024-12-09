static Network *BuildFullyConnected(const StaticShape &input_shape, NetworkType type,
                                    const std::string &name, int depth) {
  if (input_shape.height() == 0 || input_shape.width() == 0) {
    tprintf("Fully connected requires positive height and width, had %d,%d\n", input_shape.height(),
            input_shape.width());
    return nullptr;
  }
  int input_size = input_shape.height() * input_shape.width();
  int input_depth = input_size * input_shape.depth();
  Network *fc = new FullyConnected(name, input_depth, depth, type);
  if (input_size > 1) {
    auto *series = new Series("FCSeries");
    series->AddToStack(
        new Reconfig("FCReconfig", input_shape.depth(), input_shape.width(), input_shape.height()));
    series->AddToStack(fc);
    fc = series;
  }
  return fc;
}