PurpleBuddy *PurpleLine::blist_ensure_buddy(std::string uid, bool temporary) {
    PurpleBuddy *buddy = purple_find_buddy(acct, uid.c_str());
    if (buddy) {
        int flags = purple_blist_node_get_flags(PURPLE_BLIST_NODE(buddy));

        // If buddy is not temporary anymore, make them permanent.
        if ((flags & PURPLE_BLIST_NODE_FLAG_NO_SAVE) && !temporary)
        {
            purple_blist_node_set_flags(
                &buddy->node,
                (PurpleBlistNodeFlags)(flags & ~PURPLE_BLIST_NODE_FLAG_NO_SAVE));

            if (purple_buddy_get_group(buddy) == blist_ensure_group(LINE_TEMP_GROUP))
                purple_blist_add_buddy(buddy, nullptr, blist_ensure_group(LINE_GROUP), nullptr);
        }
    } else {
        buddy = purple_buddy_new(acct, uid.c_str(), uid.c_str());

        if (temporary)
            purple_blist_node_set_flags(PURPLE_BLIST_NODE(buddy), PURPLE_BLIST_NODE_FLAG_NO_SAVE);

        purple_blist_add_buddy(
            buddy,
            nullptr,
            blist_ensure_group(temporary ? LINE_TEMP_GROUP : LINE_GROUP, temporary),
            nullptr);
    }

    return buddy;
}