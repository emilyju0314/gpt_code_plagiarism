bool isSourceFileName(const Vera::Structures::SourceFiles::FileName & name)
{
    const std::string suffixes[] =
        { ".cpp", ".cxx", ".cc", ".c", ".C", ".h", ".hh", ".hpp", ".hxx", ".ipp" };

    const int numOfSuffixes = sizeof(suffixes) / sizeof(std::string);
    for (int i = 0; i != numOfSuffixes; ++i)
    {
        const std::string suf = suffixes[i];
        const Vera::Structures::SourceFiles::FileName::size_type pos = name.rfind(suf);

        if (pos != Vera::Structures::SourceFiles::FileName::npos &&
            pos == name.size() - suf.size())
        {
            return true;
        }
    }

    return false;
}