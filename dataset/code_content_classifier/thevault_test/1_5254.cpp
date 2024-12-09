size_t ts::DVBCharsetUTF8::encode(uint8_t*& buffer, size_t& size, const UString& str, size_t start, size_t count) const
{
    size_t result = 0;

    // Serialize characters as long as there is free space.
    while (buffer != nullptr && size > 0 && start < str.length() && count > 0) {
        if (str[start] != ts::CARRIAGE_RETURN) {

            // Convert a 1-character string to UTF-8.
            const std::string utf8(str.substr(start, 1).toUTF8());
            const size_t len = utf8.length();
            if (len > size) {
                // Won't fit in the buffer, stop now.
                break;
            }

            // Small optimization.
            if (len == 1) {
                *buffer = uint8_t(utf8[0]);
            }
            else {
                ::memcpy(buffer, utf8.data(), len);
            }
            buffer += len;
            size -= len;
            result++;
        }
        start++;
        count--;
    }
    return result;
}