size_t ts::DescriptorList::search(DID tag, size_t start_index, PDS pds) const
{
    bool check_pds = pds != 0 && tag >= 0x80;
    size_t index = start_index;

    while (index < _list.size() && (_list[index].desc->tag() != tag || (check_pds && _list[index].pds != pds))) {
        index++;
    }

    return index;
}