size_t ts::DescriptorList::removeByTag (DID tag, PDS pds)
{
    const bool check_pds = pds != 0 && tag >= 0x80;
    size_t removed_count = 0;

    for (ElementVector::iterator it = _list.begin(); it != _list.end(); ) {
        const DID itag = it->desc->tag();
        if (itag == tag && (!check_pds || it->pds == pds) && (itag != DID_PRIV_DATA_SPECIF || prepareRemovePDS (it))) {
            it = _list.erase (it);
            ++removed_count;
        }
        else {
            ++it;
        }
    }

    return removed_count;
}