Network *NetworkBuilder::BuildFromString(const StaticShape &input_shape, const char **str) {
  SkipWhitespace(str);
  char code_ch = **str;
  if (code_ch == '[') {
    return ParseSeries(input_shape, nullptr, str);
  }
  if (input_shape.depth() == 0) {
    // There must be an input at this point.
    return ParseInput(str);
  }
  switch (code_ch) {
    case '(':
      return ParseParallel(input_shape, str);
    case 'R':
      return ParseR(input_shape, str);
    case 'S':
      return ParseS(input_shape, str);
    case 'C':
      return ParseC(input_shape, str);
    case 'M':
      return ParseM(input_shape, str);
    case 'L':
      return ParseLSTM(input_shape, str);
    case 'F':
      return ParseFullyConnected(input_shape, str);
    case 'O':
      return ParseOutput(input_shape, str);
    default:
      tprintf("Invalid network spec:%s\n", *str);
      return nullptr;
  }
  return nullptr;
}