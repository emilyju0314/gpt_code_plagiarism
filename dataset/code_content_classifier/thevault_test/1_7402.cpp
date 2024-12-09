void pcm16_to_pcm8(const string& src, const string& dest) {
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
        int16_t* sample16 = reinterpret_cast<int16_t*>(sample);
        uint8_t sample8[2];
        sample8[0] = static_cast<uint8_t>(sample16[0] >> 8) + 128;
        sample8[1] = static_cast<uint8_t>(sample16[1] >> 8) + 128;
        out.write(reinterpret_cast<char*>(sample8), 2);
    }

    if (in.is_open()) {
        in.close();
    }

    if (out.is_open()) {
        out.close();
    }
}