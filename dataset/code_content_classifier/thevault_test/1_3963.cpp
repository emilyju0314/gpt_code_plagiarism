void HeapTable::create_if_not_exists(){

    try{
        open();
    } catch (DbException& e) {
        create();
    }
}