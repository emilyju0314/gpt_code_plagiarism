void ts::DescriptorList::addPrivateDataSpecifier(PDS pds)
{
    if (pds != 0 && (_list.size() == 0 || _list[_list.size() - 1].pds != pds)) {
        // Build a private_data_specifier_descriptor
        uint8_t data[6];
        data[0] = DID_PRIV_DATA_SPECIF;
        data[1] = 4;
        PutUInt32(data + 2, pds);
        add(DescriptorPtr(new Descriptor(data, sizeof(data))));
    }
}