void volume(const string& src, const string& dest) {
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

    while (!in.eof()) {
        in.read(sample, 4);
        int16_t* samplenum = reinterpret_cast<int16_t*>(sample);
        *samplenum = *samplenum / 2;
        out.write(sample, 4);
    }

    if (in.is_open()) {
        in.close();
    }

    if (out.is_open()) {
        out.close();
    }
}