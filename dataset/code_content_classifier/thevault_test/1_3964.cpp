Handle HeapTable::insert(const ValueDict* row){
    open();    
    Handle hand = append(validate(row));
    return hand;
}