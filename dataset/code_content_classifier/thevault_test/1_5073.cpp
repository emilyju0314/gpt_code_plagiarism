ts::UString ts::DirectoryName(const UString& path)
{
    UString::size_type sep = LastPathSeparator(path);

    if (sep == NPOS) {
        return u".";               // No '/' in path => current directory
    }
    else if (sep == 0) {
        return path.substr(0, 1);  // '/' at beginning => root
    }
    else {
        return path.substr(0, sep);
    }
}