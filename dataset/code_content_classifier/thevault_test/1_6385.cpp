std::pair<std::string, std::string>
split_first_word(const std::string& s) {
    std::pair<std::string, std::string> result;
    size_t first_end = s.find_first_of(whitespaceChars);
    if (first_end == std::string::npos) {
        result.first = s;
    } else {
        result.first = s.substr(0, first_end);
        size_t rest_begin = s.find_first_not_of(whitespaceChars, first_end);
        if (rest_begin != std::string::npos) {
            result.second = s.substr(rest_begin);
        }
    }
    return result;
}