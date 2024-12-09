size_t ts::UString::commonPrefixSize(const ts::UString &str, ts::CaseSensitivity cs) const
{
    const size_t len = std::min(length(), str.length());
    for (size_t i = 0; i < len; ++i) {
        if (cs == CASE_SENSITIVE) {
            if (at(i) != str.at(i)) {
                return i;
            }
        }
        else {
            if (ToLower(at(i)) != ToLower(str.at(i))) {
                return i;
            }
        }
    }
    return len;
}