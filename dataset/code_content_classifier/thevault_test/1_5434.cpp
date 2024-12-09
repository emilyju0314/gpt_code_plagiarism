static std::string Trim(std::string str) {

    static std::regex const re{R"(\s*(.*)\s*)"};
    std::smatch m;
    if (std::regex_match(str, m, re)) {
        str = m[1].str();
    }
    return str;
}