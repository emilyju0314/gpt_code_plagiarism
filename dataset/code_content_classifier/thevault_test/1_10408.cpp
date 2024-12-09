Network *NetworkBuilder::ParseS(const StaticShape &input_shape, const char **str) {
  char *end;
  int y = strtol(*str + 1, &end, 10);
  *str = end;
  if (**str == ',') {
    int x = strtol(*str + 1, &end, 10);
    *str = end;
    if (y <= 0 || x <= 0) {
      tprintf("Invalid S spec!:%s\n", *str);
      return nullptr;
    }
    return new Reconfig("Reconfig", input_shape.depth(), x, y);
  } else if (**str == '(') {
    // TODO(rays) Add Generic reshape.
    tprintf("Generic reshape not yet implemented!!\n");
    return nullptr;
  }
  tprintf("Invalid S spec!:%s\n", *str);
  return nullptr;
}