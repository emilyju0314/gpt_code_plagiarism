bool
Gogo::is_erroneous_name(const std::string& name)
{
  return name.compare(0, 10, ".erroneous") == 0;
}