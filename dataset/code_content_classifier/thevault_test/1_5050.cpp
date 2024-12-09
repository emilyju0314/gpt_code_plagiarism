void ts::DescriptorList::add(const DescriptorPtr& desc)
{
    PDS pds = 0;

    // Determine which PDS to associate with the descriptor
    if (desc->tag() == DID_PRIV_DATA_SPECIF) {
        // This descriptor defines a new "private data specifier".
        // The PDS is the only thing in the descriptor payload.
        pds = desc->payloadSize() < 4 ? 0 : GetUInt32(desc->payload());
    }
    else if (_list.empty()) {
        // First descriptor in the list
        pds = 0;
    }
    else {
        // Use same PDS as previous descriptor
        pds = _list[_list.size()-1].pds;
    }

    // Add the descriptor in the list
    _list.push_back(Element(desc, pds));
}