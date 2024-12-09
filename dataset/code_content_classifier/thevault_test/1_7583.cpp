std::string RemoveComments(std::string_view s) {
    size_t pos = s.find("#");

    if (pos == std::string::npos)
        return std::string(s);

    std::string fin_str(s.substr(0, pos));
    return Trim(fin_str);
}