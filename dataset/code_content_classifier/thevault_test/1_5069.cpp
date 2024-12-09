ts::UString ts::VernacularFilePath(const UString& path)
{
    UString vern(path);

#if defined(TS_WINDOWS)
    // With Windows Linux Subsystem, the syntax "/mnt/c/" means "C:\"
    if (vern.length() >= 7 && vern.startWith(u"/mnt/") && IsAlpha(vern[5]) && vern[6] == u'/') {
        vern.erase(0, 4);
    }

    // On Cygwin, the syntax "/cygdrive/C/" means "C:\"
    if (vern.startWith(u"/cygdrive/")) {
        vern.erase(0, 9);
    }

    // On Windows, transform "/c/" pattern into "C:\" (typical on Msys).
    if (vern.length() >= 3 && vern[0] == u'/' && IsAlpha(vern[1]) && vern[2] == u'/') {
        vern[0] = ToUpper(vern[1]);
        vern[1] = u':';
        vern[2] = u'\\';
    }
#endif

    // Normalize path separators.
    for (size_t i = 0; i < vern.length(); ++i) {
        if (vern[i] == u'/' || vern[i] == u'\\') {
            vern[i] = PathSeparator;
        }
    }

    return vern;
}