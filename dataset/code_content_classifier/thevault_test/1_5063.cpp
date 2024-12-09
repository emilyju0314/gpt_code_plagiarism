size_t ts::DescriptorList::search(const ts::EDID& edid, size_t start_index) const
{
    // If the EDID is table-specific, check that we are in the same table.
    // In the case the table of the descriptor list is unknown, assume that the table matches.
    const TID tid = edid.tableId();
    if (edid.isTableSpecific() && _table != nullptr && _table->tableId() != tid) {
        // No the same table, cannot match.
        return _list.size();
    }

    // Now search in the list.
    size_t index = start_index;
    while (index < _list.size() && _list[index].desc->edid(_list[index].pds, tid) != edid) {
        index++;
    }
    return index;
}