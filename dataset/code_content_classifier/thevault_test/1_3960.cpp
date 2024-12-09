void SlottedPage::put_header(RecordID id, u16 size, u16 loc) {
    if (id == 0) { 
        size = this->num_records;
        loc = this->end_free;
    }
    put_n((u16)(4*id), size);
    put_n((u16)(4*id + 2), loc);
}