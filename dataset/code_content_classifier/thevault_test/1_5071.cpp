ts::UString ts::AbsoluteFilePath(const UString& path, const UString& base)
{
    // Starting with a local form of the file path.
    UString full(VernacularFilePath(path));

    // If the path is already absolute, nothing to do.
    if (IsAbsoluteFilePath(full)) {
        return CleanupFilePath(full);
    }
    else {
        return CleanupFilePath((base.empty() ? CurrentWorkingDirectory() : base) + PathSeparator + full);
    }
}