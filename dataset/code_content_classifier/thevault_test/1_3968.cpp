ValueDict* HeapTable::project(Handle handle, const ColumnNames* column_names){
    BlockID bid = handle.first;
    RecordID rid = handle.second;
    SlottedPage* block = file.get(bid);
    Dbt* data = block->get(rid);
    ValueDict* row = unmarshal(data);
    delete data;
    delete block;
    if(column_names->empty()){
        return row;
    }
    ValueDict* res = new ValueDict();
    for(auto const& column_name: *column_names) {
        if(row->find(column_name) == row->end()){
            throw(DbRelationError("'" + column_name + "'' does not exist in table.\n"));
        }
        (*res)[column_name] = (*row)[column_name];
    }
    delete row;

    return res;     
}