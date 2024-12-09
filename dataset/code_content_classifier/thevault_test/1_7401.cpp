void speed(const string& src, const string& dest) {
    std::ifstream in(src, std::ios::in | std::ios::binary);
    std::ofstream out(dest, std::ios::out | std::ios::binary | std::ios::trunc);

    if (!in.is_open()) {
        std::cerr << "error: open " << src << " failed!" << std::endl;
        return;
    }

    if (!out.is_open()) {
        std::cerr << "error: open " << dest << " failed!" << std::endl;
        return;
    }

    char sample[4];
    long cnt = 0;

    while (!in.eof()) {
        in.read(sample, 4);
        if (cnt % 2 == 0) {
            out.write(sample, 4);
        }
        ++cnt;
    }

    if (in.is_open()) {
        in.close();
    }

    if (out.is_open()) {
        out.close();
    }
}