ts::UString ts::RelativeFilePath(const ts::UString &path, const ts::UString &base, ts::CaseSensitivity caseSensitivity, bool portableSlashes)
{
    // Build absolute file path of the target.
    UString target(AbsoluteFilePath(path));

    // Build absolute file path of the base directory, with a trailing path separator.
    UString ref(AbsoluteFilePath(base.empty() ? CurrentWorkingDirectory() : base));
    ref.append(PathSeparator);

    // See how many leading characters are matching.
    size_t same = target.commonPrefixSize(ref, caseSensitivity);

    // Move backward right after the previous path separator to
    // get the length of the common directory parts
    while (same > 0 && target[same - 1] != PathSeparator) {
        --same;
    }

    // If there is zero common character, no relative path is possible.
    // In that case, return the absolute path.
    // Note that this can normally happen on Windows only with paths
    // such as C:\foo\bar and D:\other. On Unix systems, there is at
    // least the root '/' in common.
    if (same > 0) {

        // There is a leading common part, remove it from target.
        target.erase(0, same);

        // For each remaining directory level in reference, insert a "../" in target.
        const UString up{u'.', u'.', PathSeparator};
        for (size_t i = same; i < ref.length(); ++i) {
            if (ref[i] == PathSeparator) {
                target.insert(0, up);
            }
        }
    }

    // Convert portable slashes.
    if (portableSlashes && PathSeparator != u'/') {
        target.substitute(PathSeparator, u'/');
    }

    return target;
}