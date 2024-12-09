flexible_type load_image(const std::string& url, const std::string format) {
  flexible_type ret(flex_type_enum::IMAGE);
  ret = read_image(url, format);
  return ret;
}