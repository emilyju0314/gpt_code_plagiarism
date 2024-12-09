void ProcessOutput(CryptoClientArguments const & config,
                   std::string const & name,
                   std::vector<std::byte> const & result) {

    if (config.multiline_output_) {
        config.out_ << name;
    }

    // do an 64K output loop -> avoid big mem operations on large result sets
    auto data = reinterpret_cast<char const *>(result.data());
    auto size = result.size();
    while (size > 0) {
        auto block_size = std::min(size, 64ul * 1024ul);
        ProcessOutputBlock(config, data, block_size);
        size -= block_size;
        data += block_size;
    }

    if (config.multiline_output_) {
        config.out_ << std::endl;
    }
}