bool ts::IsAbsoluteFilePath(const ts::UString& path)
{
#if defined(TS_WINDOWS)
    return path.startWith(u"\\\\") || (path.length() >= 3 && IsAlpha(path[0]) && path[1] == u':' && path[2] == u'\\');
#else
    return !path.empty() && path[0] == u'/';
#endif
}