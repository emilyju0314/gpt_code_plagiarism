static void block_trim_free(control_t* control, block_header_t* block, size_t size) {
    tlsf_assert(block_is_free(block) && "block must be free");
    if (block_can_split(block, size)) {
        block_header_t* remaining_block = block_split(block, size);
        block_link_next(block);
        block_set_prev_free(remaining_block);
        block_insert(control, remaining_block);
    }
}