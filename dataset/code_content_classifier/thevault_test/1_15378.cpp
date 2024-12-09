static void block_remove(control_t* control, block_header_t* block) {
    int fl, sl;
    mapping_insert(block_size(block), &fl, &sl);
    remove_free_block(control, block, fl, sl);
}