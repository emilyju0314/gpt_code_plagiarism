void pcm_to_wav(const string& src, const string& dest, int sample_rate,
        int bits, int channels) {
    RiffChunk riff;
    FormatChunk fmt;
    DataChunk data;

    std::ifstream in(src, std::ios::ate | std::ios::binary);
    if (!in.is_open()) {
        std::cerr << "error: open " << src << " failed!" << std::endl;
        return;
    }

    std::ofstream out(dest, std::ios::out | std::ios::binary | std::ios::trunc);
    if (!out.is_open()) {
        std::cerr << "error: open " << dest << " failed!" << std::endl;
        return;
    }

    data.chunk_size = in.tellg();

    fmt.num_channels = channels;
    fmt.sample_rate = sample_rate;
    fmt.byte_rate = sample_rate * channels * bits / 8;
    fmt.block_align = channels * bits / 8;
    fmt.bits_per_sample = bits;

    riff.chunk_size = 36 + data.chunk_size;

    // write wav file header
    out.write(reinterpret_cast<char*>(&riff), sizeof(RiffChunk));
    out.write(reinterpret_cast<char*>(&fmt), sizeof(FormatChunk));
    out.write(reinterpret_cast<char*>(&data), sizeof(DataChunk));

    char* pcm_data = new char [data.chunk_size];
    in.seekg(0, std::ios::beg);
    in.read(pcm_data, data.chunk_size);

    // write pcm data
    out.write(pcm_data, data.chunk_size);

    if (in.is_open()) {
        in.close();
    }

    if (out.is_open()) {
        out.close();
    }
}