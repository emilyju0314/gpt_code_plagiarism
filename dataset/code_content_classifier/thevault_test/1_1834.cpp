PurpleBuddy *PurpleLine::blist_update_buddy(line::Contact &contact, bool temporary) {
    contacts[contact.mid] = contact;

    if (!temporary
        && (contact.status == line::ContactStatus::FRIEND_BLOCKED
            || contact.status == line::ContactStatus::RECOMMEND_BLOCKED
            || contact.status == line::ContactStatus::DELETED
            || contact.status == line::ContactStatus::DELETED_BLOCKED))
    {
        blist_remove_buddy(contact.mid, false);
        return nullptr;
    }

    PurpleBuddy *buddy = blist_ensure_buddy(contact.mid.c_str(), temporary);
    if (!buddy) {
        purple_debug_warning("line", "Tried to update a non-existent buddy %s\n",
            contact.mid.c_str());
        return nullptr;
    }

    // Update display name
    purple_blist_alias_buddy(buddy, contact.displayName.c_str());

    // Update buddy icon if necessary
    if (contact.picturePath != "") {
        std::string pic_path = contact.picturePath.substr(1) + "/preview";
        const char *current_pic_path = purple_buddy_icons_get_checksum_for_user(buddy);
        if (!current_pic_path || std::string(current_pic_path) != pic_path) {
            std::string uid = contact.mid;

            http.request(LINE_OS_URL + pic_path, HTTPFlag::AUTH,
                [this, uid, pic_path](int status, const guchar *data, gsize len)
            {
                if (status != 200 || !data)
                    return;

                purple_buddy_icons_set_for_user(
                    acct,
                    uid.c_str(),
                    g_memdup(data, len),
                    len,
                    pic_path.c_str());
            });
        }
    } else {
        // TODO: delete icon if any
    }

    // Set actual friends as available and temporary friends as temporary. Also set status text.
    purple_prpl_got_user_status(
        acct,
        contact.mid.c_str(),
        PURPLE_BLIST_NODE_HAS_FLAG(buddy, PURPLE_BLIST_NODE_FLAG_NO_SAVE)
            ? "temporary"
            : purple_primitive_get_id_from_type(PURPLE_STATUS_AVAILABLE),
        "message", contact.statusMessage.c_str(),
        nullptr);

    if (contact.attributes & 32)
        purple_blist_node_set_bool(PURPLE_BLIST_NODE(buddy), "official_account", TRUE);
    else
        purple_blist_node_remove_setting(PURPLE_BLIST_NODE(buddy), "official_account");

    return buddy;
}