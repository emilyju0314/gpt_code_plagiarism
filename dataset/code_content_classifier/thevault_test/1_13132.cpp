DirectoryIterator::DirectoryIterator (const File& directory, bool recursive,
                                      const String& pattern, const int type)
  : wildCards (parseWildcards (pattern)),
    fileFinder (directory, (recursive || wildCards.size() > 1) ? "*" : pattern),
    wildCard (pattern),
    path (File::addTrailingSeparator (directory.getFullPathName())),
    index (-1),
    totalNumFiles (-1),
    whatToLookFor (type),
    isRecursive (recursive),
    hasBeenAdvanced (false)
{
    // you have to specify the type of files you're looking for!
    jassert ((type & (File::findFiles | File::findDirectories)) != 0);
    jassert (type > 0 && type <= 7);
}