bool ts::DescriptorList::prepareRemovePDS(const ElementVector::iterator& it)
{
    // Eliminate invalid cases
    if (it == _list.end() || it->desc->tag() != DID_PRIV_DATA_SPECIF) {
        return false;
    }

    // Search for private descriptors ahead.
    ElementVector::iterator end;
    for (end = it + 1; end != _list.end(); ++end) {
        DID tag = end->desc->tag();
        if (tag >= 0x80) {
            // This is a private descriptor, the private_data_specifier descriptor
            // is necessary and cannot be removed.
            return false;
        }
        if (tag == DID_PRIV_DATA_SPECIF) {
            // Found another private_data_specifier descriptor with no private
            // descriptor between the two => the first one can be removed.
            break;
        }
    }

    // Update the current PDS after removed private_data_specifier descriptor
    uint32_t previous_pds = it == _list.begin() ? 0 : (it-1)->pds;
    while (--end != it) {
        end->pds = previous_pds;
    }

    return true;
}