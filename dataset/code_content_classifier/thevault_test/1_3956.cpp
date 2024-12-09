void SlottedPage::put(RecordID record_id, const Dbt &data) throw(DbBlockNoRoomError){
    u16 size, loc;
    get_header(size, loc, record_id);
    u16 new_size = (u16)data.get_size();

    if (new_size > size) {
        u16 extra = new_size - size;

        if (!has_room(extra))
            throw DbBlockNoRoomError("not enough room for enlarged record (SlottedPage::put)");
        
        slide(loc, loc - extra);
        memcpy(this->address(loc-extra), data.get_data(), new_size);       
    } else {
        memcpy(this->address(loc), data.get_data(), new_size);
        slide(loc + new_size, loc + size);
    }
    //if (!has_room(new_size))
    //    throw DbBlockNoRoomError("Not enough space");
    //if (new_size > size){
    //    slide(loc,loc-new_size-size);
    //    memcpy(address(loc-new_size-size), data.get_data(),new_size);
    //}
    //else{
    //    memcpy(address(loc),data.get_data(),new_size);
    //    slide(loc+new_size,loc+size);
    //}
    get_header(size,loc,record_id);
    put_header(record_id, new_size, loc);
}