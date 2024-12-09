Handles* HeapTable::select(const ValueDict* where) {
    open();
    Handles* handles = new Handles();
    BlockIDs* block_ids = file.block_ids();

    for (auto const& block_id: *block_ids) {
        SlottedPage* block = file.get(block_id);
        RecordIDs* record_ids = block->ids();

        for (auto const& record_id: *record_ids) {
            Handle handle(block_id, record_id);
            if (selected(handle, where))
                handles->push_back(Handle(block_id, record_id));
        }           
        delete record_ids;
        delete block;
    }

    delete block_ids;
    return handles;
}