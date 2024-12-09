void split(const string& src, const string& left, const string& right) {
    std::ifstream in(src, std::ios::in | std::ios::binary);
    std::ofstream channel1(left, std::ios::out | std::ios::trunc | std::ios::binary);
    std::ofstream channel2(right, std::ios::out | std::ios::trunc | std::ios::binary);

    if (!in.is_open()) {
        std::cerr << "error: open " << src << " failed!" << std::endl;
        return;
    }

    if (!channel1.is_open()) {
        std::cerr << "error: open " << left << " failed!" << std::endl;
        return;
    }

    if (!channel2.is_open()) {
        std::cerr << "error: open " << right << " failed!" << std::endl;
        return;
    }

    char sample[4];

    while (!in.eof()) {
        in.read(sample, 4);
        channel1.write(sample, 2);
        channel2.write(sample + 2, 2);
    }

    if (in.is_open()) {
        in.close();
    }

    if (channel1.is_open()) {
        channel1.close();
    }

    if (channel2.is_open()) {
        channel2.close();
    }
}