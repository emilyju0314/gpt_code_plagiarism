ts::UString ts::AddPathSuffix(const UString& path, const UString& suffix)
{
    UString::size_type sep = LastPathSeparator(path);
    UString::size_type dot = path.rfind(u'.');

    if (dot == NPOS || (sep != NPOS && dot < sep)) {
        return path + suffix;
    }
    else {
        return path;
    }
}