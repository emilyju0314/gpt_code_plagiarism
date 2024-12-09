void ts::PrefetchDescriptor::DisplayDescriptor(TablesDisplay& display, DID did, const uint8_t* data, size_t size, int indent, TID tid, PDS pds)
{
    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');

    if (size >= 1) {
        strm << margin << UString::Format(u"Transport protocol label: 0x%X (%d)", {data[0], data[0]}) << std::endl;
        data++; size--;
        while (size >= 1) {
            const size_t len = data[0];
            if (len + 2 > size) {
                break;
            }
            strm << margin
                 << UString::Format(u"Label: \"%s\", prefetch priority: %d", {display.duck().fromDVB(data + 1, len), data[len + 1]})
                 << std::endl;
            data += len + 2; size -= len + 2;
        }
    }

    display.displayExtraData(data, size, indent);
}