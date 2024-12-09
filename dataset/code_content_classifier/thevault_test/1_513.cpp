std::string read_fen_from_file(const std::string& file_name, int line_num) {
    std::string fen;
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
            if(i == line_num) {
                fen = line; // maybe I should just return here and hope it closes on during destruction
            }
        }

        if (in.bad()) {
            throw std::runtime_error("Runtime error in read_fen_from_file(const std::string&, const uint32): Badbit file.");
        }

        in.close();
    } catch(const std::exception& e) {
        throw;
    }

    return fen;
}