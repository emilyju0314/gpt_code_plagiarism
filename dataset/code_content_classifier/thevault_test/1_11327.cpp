inline SEXP unserializeFromStr(std::string s) {
    // parse the std::string into a raw vector
    std::vector<std::string> strs;
    boost::regex e("^\\d.+");
    if (boost::regex_match(s, e)) {
        boost::split(strs,s,boost::is_any_of("\t"));
    }

    Rcpp::RawVector object(strs.size() - 1);

    for (size_t i = 0; i < strs.size() - 1; i++) {
        object[i] = static_cast<unsigned char>(std::stoi(strs[i]));
    }

    return unserializeFromRaw(object);
}