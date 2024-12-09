static std::string GetBlockSizeText(std::uint64_t size) {
    if (size != 0) {
        return std::to_string(size) + " Bytes";
    }
    return std::string{"n/a"};
}