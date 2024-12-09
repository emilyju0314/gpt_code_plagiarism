void void_handler(std::exception& e)
{
 std::string s = std::string("void handler() called, caught: ") + e.what();
 INFO(s);
}