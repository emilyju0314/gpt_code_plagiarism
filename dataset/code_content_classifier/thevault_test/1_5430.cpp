void ProcessOutputBlock(CryptoClientArguments const & config, char const * data, std::uint64_t size) {

    if (config.hex_output_ || config.multiline_output_) {
        auto hex = headcode::mem::MemoryToHex(data, size);
        config.out_ << hex;
    } else {
        try {
            config.out_.write(data, size);
        } catch (std::exception & ex) {
            config.err_ << "Failed to write output: " << ex.what() << std::endl;
        }
    }
}