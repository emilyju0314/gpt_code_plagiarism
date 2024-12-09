std::string allpix::from_string_impl(std::string str, type_tag<std::string>) {
    str = trim(str);
    // If there are "" then we should take the whole string
    if(!str.empty() && (str.front() == '\"' || str.front() == '\'')) {
        if(str.find(str.front(), 1) != str.size() - 1) {
            throw std::invalid_argument("remaining data at end");
        }
        return str.substr(1, str.size() - 2);
    }
    // Otherwise read a single string
    return from_string_helper(str);
}