const char *convert_handler(std::exception&)
{
 static const char *s = "Hello from convert_handler()";
 return s;
}