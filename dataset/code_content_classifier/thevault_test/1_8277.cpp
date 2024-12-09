std::string
Gogo::erroneous_name()
{
  go_assert(saw_errors());
  static int erroneous_count;
  char name[50];
  snprintf(name, sizeof name, ".erroneous%d", erroneous_count);
  ++erroneous_count;
  return name;
}