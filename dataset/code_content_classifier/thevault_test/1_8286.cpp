std::string
Gogo::initializer_name()
{
  static unsigned int counter;
  char buf[30];
  ++counter;
  snprintf(buf, sizeof buf, "go..C%u", counter);
  return buf;
}