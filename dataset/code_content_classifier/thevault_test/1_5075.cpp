ts::UString ts::PathSuffix(const UString& path)
{
    UString::size_type sep = LastPathSeparator(path);
    UString::size_type dot = path.rfind(u'.');

    if (dot == NPOS) {
        return ts::UString();  // no dot in path
    }
    else if (sep != NPOS && dot < sep) {
        return ts::UString();  // dot in directory part, not in base name
    }
    else {
        return path.substr(dot); // dot in base name
    }
}