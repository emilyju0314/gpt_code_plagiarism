void RemoveExtension (std::string& path)
{
    std::string::size_type dotPos = path.rfind('.');
    if (dotPos != std::string::npos)
        path.erase(dotPos);
}