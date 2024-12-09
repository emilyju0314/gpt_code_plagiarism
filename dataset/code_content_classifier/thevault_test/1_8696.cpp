static size_t
str_concat(char *dst, size_t dst_len, const char *src, size_t src_len)
{
  size_t to_copy = std::min(dst_len, src_len);

  if (to_copy > 0) {
    strncat(dst, src, to_copy);
  }

  return to_copy;
}