bool Utils::isDir(const std::string& path)
{
    boost::filesystem::path check_path(path);
    if (boost::filesystem::exists(check_path))
    {
        return boost::filesystem::is_directory(path);
    }
    return false;
}