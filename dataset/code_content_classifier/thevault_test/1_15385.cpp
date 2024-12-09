static void block_trim_used(control_t* control, block_header_t* block, size_t size) {
    tlsf_assert(!block_is_free(block) && "block must be used");
    if (block_can_split(block, size)) {
        /* If the next block is free, we must coalesce. */
        block_header_t* remaining_block = block_split(block, size);
        block_set_prev_used(remaining_block);

        remaining_block = block_merge_next(control, remaining_block);
        block_insert(control, remaining_block);
    }
}