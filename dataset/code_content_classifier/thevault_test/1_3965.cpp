void HeapTable::del(const Handle handle){
	open();
	BlockID block_id = handle.first;
	RecordID record_id = handle.second;
	SlottedPage* block = this->file.get(block_id);
	block->del(record_id);
	this->file.put(block);
	delete block;
}