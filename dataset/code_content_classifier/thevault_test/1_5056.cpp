bool ts::DescriptorList::removeByIndex(size_t index)
{
    // Check index validity
    if (index >= _list.size()) {
        return false;
    }

    // Private_data_specifier descriptor can be removed under certain conditions only
    if (_list[index].desc->tag() == DID_PRIV_DATA_SPECIF && !prepareRemovePDS(_list.begin() + index)) {
        return false;
    }

    // Remove the specified descriptor
    _list.erase(_list.begin() + index);
    return true;
}