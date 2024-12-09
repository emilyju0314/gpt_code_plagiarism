void ts::UpdateDescriptor::DisplayDescriptor(TablesDisplay& display, DID did, const uint8_t* data, size_t size, int indent, TID tid, PDS pds)
{
    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');

    if (size > 0) {
        strm << margin << "Update flag: " << NameFromSection(u"SSUUpdateFlag", (data[0] >> 6) & 0x03, names::DECIMAL_FIRST) << std::endl
             << margin << "Update method: " << NameFromSection(u"SSUUpdateMethod", (data[0] >> 2) & 0x0F, names::DECIMAL_FIRST) << std::endl
             << margin << UString::Format(u"Update priority: %d", {data[0] & 0x03}) << std::endl;
        if (size > 1) {
            strm << margin << "Private data:" << std::endl
                 << UString::Dump(data + 1, size - 1, UString::HEXA | UString::ASCII | UString::OFFSET, indent);
        }
    }
}