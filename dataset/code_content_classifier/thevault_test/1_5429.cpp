int Add(std::unique_ptr<headcode::crypt::Algorithm> & algorithm,
        FILE * stream,
        std::vector<std::byte> & result,
        std::ostream & err) {

    std::uint64_t total_read = 0;
    std::vector<std::byte> incoming;
    incoming.resize(64 * 1024);

    while (stream && !std::feof(stream)) {

        std::uint64_t read = 0;
        try {
            read = std::fread(incoming.data(), 1, incoming.size(), stream);
            incoming.resize(read);
        } catch (std::exception & ex) {
            err << "Failed to read data: " << ex.what();
            return 1;
        }

        if (read > 0) {

            std::vector<std::byte> outgoing;
            outgoing.resize(64 * 1024);

            algorithm->Add(incoming, outgoing);
            if (!outgoing.empty()) {
                result.resize(result.size() + outgoing.size());
                std::memcpy(result.data() + result.size() - outgoing.size(), outgoing.data(), outgoing.size());
            }

            total_read += read;
        }
    }

    return 0;
}