static size_t adjust_request_size(size_t size, size_t align) {
    size_t adjust = 0;
    if (size && size < block_size_max) {
        const size_t aligned = align_up(size, align);
        adjust = tlsf_max(aligned, block_size_min);
    }
    return adjust;
}