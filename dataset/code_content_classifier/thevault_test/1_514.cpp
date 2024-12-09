std::vector<std::string> read_all_fen_from_file(const std::string& file_name) {
    std::vector<std::string> fen_vec;
    std::string line;

    try {
        std::fstream in(file_name);
        in.exceptions(std::ifstream::badbit);
        if (!in.is_open()) {
            std::string err("Failed to open file: ");
            err += file_name;
            throw std::runtime_error(err);
        }

        for (int i = 1; std::getline(in, line); i++) {
            fen_vec.push_back(line);
        }

        if (in.bad()) {
            throw std::runtime_error("Runtime error in read_all_fen_from_file(const std::string&, const uint32): Badbit file.");
        }

        in.close();
    } catch (const std::exception& e) {
        throw;
    }

    return fen_vec;
}