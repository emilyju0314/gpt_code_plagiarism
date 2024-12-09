bool HeapTable::selected(Handle handle, const ValueDict* where) {
	if (where == nullptr)
		return true;
	ValueDict* row = this->project(handle, where);
	return *row == *where;
}