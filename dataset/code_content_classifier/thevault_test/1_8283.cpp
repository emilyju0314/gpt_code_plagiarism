std::string
Gogo::redefined_function_name()
{
  static int redefinition_count;
  char buf[30];
  snprintf(buf, sizeof buf, ".redefined%d", redefinition_count);
  ++redefinition_count;
  return buf;
}