bool is_help_arg(std::string arg)
{
    if (arg == "-h") return true;
    if (arg == "--h") return true;
    if (arg == "-help") return true;
    if (arg == "--help") return true;
    return false;
}