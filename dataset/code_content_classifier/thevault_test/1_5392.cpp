bool ts::AbstractTransportListTable::getNextTransport(TransportStreamIdSet& ts_set,
                                                      TransportStreamId& ts_id,
                                                      int section_number) const
{
    // Search one TS which should be serialized in current section
    for (auto it = ts_set.begin(); it != ts_set.end(); ++it) {
        if (transports[*it].preferred_section == section_number) {
            ts_id = *it;
            ts_set.erase(it);
            return true;
        }
    }

    // No transport for this section.
    // Search one TS without section hint or with a previous section hint.
    for (auto it = ts_set.begin(); it != ts_set.end(); ++it) {
        if (transports[*it].preferred_section < section_number) { // including preferred_section == -1
            ts_id = *it;
            ts_set.erase(it);
            return true;
        }
    }

    // No TS found. Either no more TS in ts_set or all remaining TS have
    // a section hint for subsequent sections.
    return false;
}