char* EscapeReverse(arrow::util::string_view s, char* out_end) {
  for (const char* val = s.data() + s.length() - 1; val >= s.data(); val--, out_end--) {
    if (*val == '"') {
      *out_end = *val;
      out_end--;
    }
    *out_end = *val;
  }
  return out_end;
}