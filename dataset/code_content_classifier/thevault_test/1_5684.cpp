int convertToString(const char* filename, std::string& s) {
    std::ifstream file(filename, std::ios::binary);
    if(file.is_open()) {
        file.seekg(0, std::fstream::end);
        size_t size = file.tellg();
        file.seekg(0, std::fstream::beg);
        s.resize(size);
        file.read(&s[0], size);
        file.close();
        return 0;
    }
    return FAILURE;
}