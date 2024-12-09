ValueDict* HeapTable::validate(const ValueDict* row) const {
	ValueDict* result = new ValueDict();
    Value value;
    ValueDict::const_iterator rowInfo;
    for (ColumnNames::const_iterator i = column_names.begin(); i != column_names.end(); i++) {
        rowInfo = row->find(*i);
        if(rowInfo==row->end()){
            throw DbRelationError("don't know how to handle NULLs, defaults, etc. yet");
        } else {
            value = rowInfo->second;
        }
        (*result) [*i] = value;
    }

    return result;
}