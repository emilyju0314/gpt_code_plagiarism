void error(const std::string& msg)
{
    fprintf(stderr, "%s\n", msg.c_str());
    ++err_count;
}