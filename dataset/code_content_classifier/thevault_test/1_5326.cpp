bool ts::UString::save(const ts::UString& fileName, bool append, bool enforceLastLineFeed) const
{
    std::ofstream file(fileName.toUTF8().c_str(), append ? (std::ios::out | std::ios::app) : std::ios::out);
    file << *this;
    if (enforceLastLineFeed && !empty() && back() != LINE_FEED) {
        // Check if the first end of line is a LF or CR/LF.
        // Use the same eol sequence for the last one, regardless of the system.
        const size_type lf = find(LINE_FEED);
        if (lf != NPOS && lf > 0 && (*this)[lf-1] == CARRIAGE_RETURN) {
            // The first eol is a CR/LF.
            file << "\r\n";
        }
        else {
            file << '\n';
        }
    }
    file.close();
    return !file.fail();
}