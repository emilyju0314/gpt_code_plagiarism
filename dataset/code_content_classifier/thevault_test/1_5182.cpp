void ts::ContentAdvisoryDescriptor::DisplayDescriptor(TablesDisplay& display, DID did, const uint8_t* data, size_t size, int indent, TID tid, PDS pds)
{
    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');

    if (size >= 1) {
        size_t reg_count = data[0] & 0x3F;
        data++; size--;
        strm << margin << "Number of regions: " << reg_count << std::endl;
        while (size >= 2 && reg_count > 0) {
            size_t dim_count = data[1];
            strm << margin << UString::Format(u"- Rating region: 0x%X (%d), number of dimensions: %d", {data[0], data[0], dim_count}) << std::endl;
            data += 2; size -= 2;
            while (size >= 2 && dim_count > 0) {
                strm << margin << UString::Format(u"    Rating dimension j: 0x%X (%d), rating value: %d", {data[0], data[0], data[1] & 0x0F}) << std::endl;
                data += 2; size -= 2; dim_count--;
            }
            if (size >= 1) {
                size_t len = data[0];
                data++; size--;
                ATSCMultipleString::Display(display, u"Rating description: ", indent + 2, data, size, len);
            }
            reg_count--;
        }
    }

    display.displayExtraData(data, size, indent);
}