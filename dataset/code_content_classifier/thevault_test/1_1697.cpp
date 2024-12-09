std::pair<bool, std::string>
read_file(const std::string& path) {
    auto line = std::string{};
    auto content = std::string{};
    auto file = std::ifstream{ path };

    if (file.is_open()) {
        while (getline(file, line)) { content += line + "\n"; }
        file.close();
    } else {
        return std::make_pair(false, std::string{});
    }

    return std::make_pair(true, content);
}