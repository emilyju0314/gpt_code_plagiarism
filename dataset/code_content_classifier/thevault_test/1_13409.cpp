bool Utils::fileExist(const std::string& path) throw()
{
    if (access(path.c_str(), F_OK) == 0)
        return true;
    return false;
}