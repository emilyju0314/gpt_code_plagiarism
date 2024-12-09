void PurpleLine::blist_update_buddy(std::string uid, bool temporary) {
    // Put buddy on list already so it shows up as loading
    blist_ensure_buddy(uid.c_str(), temporary);

    c_out->send_getContact(uid);
    c_out->send([this, temporary]{
        line::Contact contact;
        c_out->recv_getContact(contact);

        if (contact.__isset.mid)
            blist_update_buddy(contact, temporary);
    });
}