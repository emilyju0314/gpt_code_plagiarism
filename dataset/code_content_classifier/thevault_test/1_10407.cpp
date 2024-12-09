Network *NetworkBuilder::ParseR(const StaticShape &input_shape, const char **str) {
  char dir = (*str)[1];
  if (dir == 'x' || dir == 'y') {
    std::string name = "Reverse";
    name += dir;
    *str += 2;
    Network *network = BuildFromString(input_shape, str);
    if (network == nullptr) {
      return nullptr;
    }
    auto *rev = new Reversed(name, dir == 'y' ? NT_YREVERSED : NT_XREVERSED);
    rev->SetNetwork(network);
    return rev;
  }
  char *end;
  int replicas = strtol(*str + 1, &end, 10);
  *str = end;
  if (replicas <= 0) {
    tprintf("Invalid R spec!:%s\n", end);
    return nullptr;
  }
  auto *parallel = new Parallel("Replicated", NT_REPLICATED);
  const char *str_copy = *str;
  for (int i = 0; i < replicas; ++i) {
    str_copy = *str;
    Network *network = BuildFromString(input_shape, &str_copy);
    if (network == nullptr) {
      tprintf("Invalid replicated network!\n");
      delete parallel;
      return nullptr;
    }
    parallel->AddToStack(network);
  }
  *str = str_copy;
  return parallel;
}