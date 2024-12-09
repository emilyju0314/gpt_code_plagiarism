std::string StripXPSysDir (const std::string& path)
{
    // does the path begin with it?
    if (path.find(GetXPSystemPath()) == 0)
        return path.substr(GetXPSystemPath().length());
    else
        return path;
}