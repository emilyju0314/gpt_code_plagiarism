u16 SlottedPage::size() const {
    u16 size, loc;
    u16 count = 0;
    for (RecordID record_id = 1; record_id <= this->num_records; record_id++) {
        get_header(size, loc, record_id);
        if (loc != 0)
            count++;
    }
    return count;
}