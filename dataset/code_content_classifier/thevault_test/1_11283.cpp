size_t sframe_row_to_csv(const std::vector<flexible_type>& row, char* buf, size_t buflen) {
  flexible_type val;
  char* cur = buf;
  int space_remaining = buflen;
  int last_bytes_written = 0;
  for(size_t i = 0; (i < row.size()) && (space_remaining); ++i) {
    val = row[i];
    switch(val.get_type()) {
      case flex_type_enum::STRING:
        last_bytes_written = snprintf(cur, space_remaining, "\"%s\"", val.get<flex_string>().c_str());
        break;
      case flex_type_enum::FLOAT:
        last_bytes_written = snprintf(cur, space_remaining, "%f", val.get<flex_float>());
        break;
      case flex_type_enum::INTEGER:
        last_bytes_written = snprintf(cur, space_remaining, "%ld", val.get<flex_int>());
        break;
      case flex_type_enum::UNDEFINED:
        last_bytes_written = 0;
        break;
      default:
        last_bytes_written = snprintf(cur, space_remaining, "%s", ((std::string)val).c_str());
        break;
    }
    if (last_bytes_written < 0 || last_bytes_written >= space_remaining) {
      return buflen;
    } else {
      cur += last_bytes_written;
      space_remaining -= last_bytes_written;
      if (space_remaining) {
        if (i == row.size()-1) {
          *cur++ = '\n';
          --space_remaining;
        } else {
          *cur++ = ',';
          --space_remaining;
        }
      } else {
        break;
      }
    }
  }
  return (cur - buf);
}