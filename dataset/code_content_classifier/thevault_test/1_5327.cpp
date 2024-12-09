bool ts::UString::getLine(std::istream& strm)
{
    std::string line;

    if (!std::getline(strm, line)) {
        // File read error.
        clear();
        return false;
    }
    else {
        const char* start = line.data();
        size_type len = line.size();

        // Remove potential trailing mixed CR/LF characters
        while (len > 0 && (start[len - 1] == '\r' || start[len - 1] == '\n')) {
            --len;
        }

        // Remove potential UTF-8 BOM (Byte Order Mark) at beginning of line.
        if (len >= UTF8_BOM_SIZE && line.compare(0, UTF8_BOM_SIZE, UTF8_BOM, UTF8_BOM_SIZE) == 0) {
            start += UTF8_BOM_SIZE;
            len -= UTF8_BOM_SIZE;
        }

        // Convert from UTF-8 to UTF-16.
        assignFromUTF8(start, len);
        return true;
    }
}