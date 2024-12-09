std::string
Gogo::sink_function_name()
{
  static int sink_count;
  char buf[30];
  snprintf(buf, sizeof buf, ".sink%d", sink_count);
  ++sink_count;
  return buf;
}