void SlottedPage::slide(u16 start, u16 end){
    int shift = end - start;

    // If there is no shift, do nothing
    if (shift == 0)
        return;

    // Move data
    //memcpy((u16)(this->address(end_free+1)), (u16)(this->address(end_free+1+shift)),shift);
    void *to = this->address((u16)(this->end_free + 1 + shift));
    void *from = this->address((u16)(this->end_free + 1));
    int bytes = start - (this->end_free + 1U);
    char temp[bytes];
    memcpy(temp, from, bytes);
    memcpy(to, temp, bytes);

    RecordIDs* record_ids = ids();
	for (auto const& record_id : *record_ids) {
		u16 size, loc;
		get_header(size, loc, record_id);
		if (loc <= start) {
			loc += shift;
			put_header(record_id, size, loc);
		}
	}
    delete record_ids;
    this->end_free += shift;
    put_header();
}