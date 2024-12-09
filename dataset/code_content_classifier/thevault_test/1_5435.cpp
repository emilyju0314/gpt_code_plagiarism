static std::vector<std::string> Split(std::string const & str, char delim = '\n') {

    std::vector<std::string> res;
    res.clear();

    std::stringstream ss{str};
    std::string line;
    while (std::getline(ss, line, delim)) {
        res.push_back(line);
    }

    return res;
}