std::string EscapeAssertion(std::string s) {
    std::regex regex_s("[a-zA-Z0-9. ]+");

    std::sregex_iterator words_begin = std::sregex_iterator(s.begin(), s.end(), regex_s); 
    auto words_end = std::sregex_iterator();

    for (std::sregex_iterator k = words_begin; k != words_end; ++k) {
        std::smatch match = *k;
        std::string match_str = match.str();
        int pos = static_cast<int>(match_str.find("."));
        if(pos!=-1) {
            std::string new_str = match_str.replace(pos, 1, "_");
            s = s.replace(match.position(), match.str().length(), new_str);
        }
    }

    return s;
}