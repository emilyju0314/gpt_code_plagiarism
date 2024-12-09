void PurpleLine::blist_update_chat(std::string id, ChatType type) {
    // Put buddy on list already so it shows up as loading
    blist_ensure_chat(id.c_str(), type);

    if (type == ChatType::GROUP) {
        c_out->send_getGroup(id);
        c_out->send([this]{
            line::Group group;
            c_out->recv_getGroup(group);

            if (group.__isset.id)
                blist_update_chat(group);
        });
    } else if (type == ChatType::ROOM) {
        c_out->send_getRoom(id);
        c_out->send([this]{
            line::Room room;
            c_out->recv_getRoom(room);

            if (room.__isset.mid)
                blist_update_chat(room);
        });
    }
}