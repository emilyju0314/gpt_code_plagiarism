void ts::DataBroadcastDescriptor::DisplayDescriptor(TablesDisplay& display, DID did, const uint8_t* data, size_t size, int indent, TID tid, PDS pds)
{
    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');

    if (size >= 4) {
        const uint16_t dbid = GetUInt16(data);
        const uint8_t ctag = data[2];
        size_t slength = data[3];
        data += 4; size -= 4;
        if (slength > size) {
            slength = size;
        }
        strm << margin << "Data broadcast id: " << names::DataBroadcastId(dbid, names::BOTH_FIRST) << std::endl
             << margin << UString::Format(u"Component tag: %d (0x%X), ", {ctag, ctag})
             << std::endl;
        DataBroadcastIdDescriptor::DisplaySelectorBytes(display, data, slength, indent, dbid);
        data += slength; size -= slength;
        if (size >= 3) {
            strm << margin << "Language: " << DeserializeLanguageCode(data) << std::endl;
            data += 3; size -= 3;
            strm << margin << "Description: \"" << display.duck().fromDVBWithByteLength(data, size) << "\"" << std::endl;
        }
    }

    display.displayExtraData(data, size, indent);
}