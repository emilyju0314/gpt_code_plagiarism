static block_header_t* block_link_next(block_header_t* block) {
    block_header_t* next = block_next(block);
    next->prev_phys_block = block;
    return next;
}