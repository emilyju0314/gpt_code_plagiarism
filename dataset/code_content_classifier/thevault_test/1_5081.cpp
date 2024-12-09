bool ts::IsSymbolicLink(const UString& path)
{
#if defined(TS_UNIX)
    struct stat st;
    TS_ZERO(st);
    if (::lstat(path.toUTF8().c_str(), &st) != 0) {
        return false; // lstat() error
    }
    else {
        return (st.st_mode & S_IFMT) == S_IFLNK;
    }
#else
    // Non Unix systems, no symbolic links.
    return false;
#endif
}