static block_header_t* block_merge_prev(control_t* control, block_header_t* block) {
    if (block_is_prev_free(block)) {
        block_header_t* prev = block_prev(block);
        tlsf_assert(prev && "prev physical block can't be null");
        tlsf_assert(block_is_free(prev) && "prev block is not free though marked as such");
        block_remove(control, prev);
        block = block_absorb(prev, block);
    }

    return block;
}