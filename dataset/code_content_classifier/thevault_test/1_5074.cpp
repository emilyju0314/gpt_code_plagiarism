ts::UString ts::BaseName(const UString& path, const UString& suffix)
{
    const UString::size_type sep = LastPathSeparator(path);
    const UString base(path.substr(sep == NPOS ? 0 : sep + 1));
    const bool suffixFound = !suffix.empty() && base.endWith(suffix, FileSystemCaseSensitivity);
    return suffixFound ? base.substr(0, base.size() - suffix.size()) : base;
}