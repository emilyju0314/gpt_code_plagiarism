static block_header_t* block_merge_next(control_t* control, block_header_t* block) {
    block_header_t* next = block_next(block);
    tlsf_assert(next && "next physical block can't be null");

    if (block_is_free(next)) {
        tlsf_assert(!block_is_last(block) && "previous block can't be last");
        block_remove(control, next);
        block = block_absorb(block, next);
    }

    return block;
}