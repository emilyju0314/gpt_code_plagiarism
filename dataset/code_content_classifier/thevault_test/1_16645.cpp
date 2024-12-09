FilePath FilePath::DirName() const
{
    FilePath new_path(path_);
    new_path.StripTrailingSeparatorsInternal();

    // The drive letter, if any, always needs to remain in the output.  If there
    // is no drive letter, as will always be the case on platforms which do not
    // support drive letters, letter will be npos, or -1, so the comparisons and
    // resizes below using letter will still be valid.
    int letter = FindDriveLetter(new_path.path_);

    int last_separator = new_path.path_.reverseFind(kSeparators);
    if (last_separator == -1) {
        // path_ is in the current directory.
        new_path.path_.truncate(letter + 1);
    } else if (last_separator == letter + 1) {
        // path_ is in the root directory.
        new_path.path_.truncate(letter + 2);
    } else if (last_separator == letter + 2 &&
            IsSeparator(new_path.path_.utf8().data()[letter + 1])) {
        // path_ is in "//" (possibly with a drive letter); leave the double
        // separator intact indicating alternate root.
        new_path.path_.truncate(letter + 3);
    } else if (last_separator != 0) {
        // path_ is somewhere else, trim the basename.
        new_path.path_.truncate(last_separator);
    }

    new_path.StripTrailingSeparatorsInternal();
    if (!new_path.path_.length())
        new_path.path_ = kCurrentDirectory;

    return new_path;
}