static block_header_t* block_next(const block_header_t* block) {
    block_header_t* next =
        offset_to_block(block_to_ptr(block), block_size(block) - block_header_overhead);
    tlsf_assert(!block_is_last(block));
    return next;
}