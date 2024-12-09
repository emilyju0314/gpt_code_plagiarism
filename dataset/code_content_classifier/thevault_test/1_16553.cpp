std::string Program::decorate(const std::string &string)
{
    if (string.substr(0, 3) != "gl_" && string.substr(0, 3) != "dx_")
    {
        return "_" + string;
    }
    else
    {
        return string;
    }
}