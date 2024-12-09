Dbt* SlottedPage::get(RecordID record_id) const{

	u16 size, loc;
	get_header(size, loc, record_id);

	if(loc == 0){
		return nullptr;
	}
	
	return new Dbt(this->address(loc),size);
}