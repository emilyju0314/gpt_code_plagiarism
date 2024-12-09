Network *NetworkBuilder::ParseInput(const char **str) {
  // There must be an input at this point.
  int length = 0;
  int batch, height, width, depth;
  int num_converted = sscanf(*str, "%d,%d,%d,%d%n", &batch, &height, &width, &depth, &length);
  StaticShape shape;
  shape.SetShape(batch, height, width, depth);
  // num_converted may or may not include the length.
  if (num_converted != 4 && num_converted != 5) {
    tprintf("Must specify an input layer as the first layer, not %s!!\n", *str);
    return nullptr;
  }
  *str += length;
  auto *input = new Input("Input", shape);
  // We want to allow [<input>rest of net... or <input>[rest of net... so we
  // have to check explicitly for '[' here.
  SkipWhitespace(str);
  if (**str == '[') {
    return ParseSeries(shape, input, str);
  }
  return input;
}