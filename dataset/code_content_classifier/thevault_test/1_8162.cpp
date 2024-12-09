bool ConsumeDurationUnit(const wchar_t **start, const wchar_t *end, Duration *unit) {
  size_t size = end - *start;
  switch (size) {
  case 0:
    return false;
  default:
    switch (**start) {
    case L'n':
      if (*(*start + 1) == L's') {
        *start += 2;
        *unit = Nanoseconds(1);
        return true;
      }
      break;
    case L'u':
      if (*(*start + 1) == L's') {
        *start += 2;
        *unit = Microseconds(1);
        return true;
      }
      break;
    case L'm':
      if (*(*start + 1) == L's') {
        *start += 2;
        *unit = Milliseconds(1);
        return true;
      }
      break;
    default:
      break;
    }
    [[fallthrough]];
  case 1:
    switch (**start) {
    case L's':
      *unit = Seconds(1);
      *start += 1;
      return true;
    case L'm':
      *unit = Minutes(1);
      *start += 1;
      return true;
    case L'h':
      *unit = Hours(1);
      *start += 1;
      return true;
    default:
      return false;
    }
  }
}