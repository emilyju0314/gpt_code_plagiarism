RecordIDs* SlottedPage::ids(void) const {
    u16 size, loc;
    RecordIDs* records = new RecordIDs;
    for (u16 i = 1; i <= num_records; i++){
    	get_header(size, loc, i);
    	if(loc != 0)
    		records->push_back(i);
    }
    return records;
}