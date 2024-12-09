static void remove_free_block(control_t* control, block_header_t* block, int fl, int sl) {
    block_header_t* prev = block->prev_free;
    block_header_t* next = block->next_free;
    tlsf_assert(prev && "prev_free field can not be null");
    tlsf_assert(next && "next_free field can not be null");
    next->prev_free = prev;
    prev->next_free = next;

    /* If this block is the head of the free list, set new head. */
    if (control->blocks[fl][sl] == block) {
        control->blocks[fl][sl] = next;

        /* If the new head is null, clear the bitmap. */
        if (next == &control->block_null) {
            control->sl_bitmap[fl] &= ~(1 << sl);

            /* If the second bitmap is now empty, clear the fl bitmap. */
            if (!control->sl_bitmap[fl]) {
                control->fl_bitmap &= ~(1 << fl);
            }
        }
    }
}