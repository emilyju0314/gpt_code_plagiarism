Network *NetworkBuilder::ParseFullyConnected(const StaticShape &input_shape, const char **str) {
  const char *spec_start = *str;
  NetworkType type = NonLinearity((*str)[1]);
  if (type == NT_NONE) {
    tprintf("Invalid nonlinearity on F-spec!: %s\n", *str);
    return nullptr;
  }
  char *end;
  int depth = strtol(*str + 2, &end, 10);
  if (depth <= 0) {
    tprintf("Invalid F spec!:%s\n", *str);
    return nullptr;
  }
  *str = end;
  std::string name(spec_start, *str - spec_start);
  return BuildFullyConnected(input_shape, type, name, depth);
}