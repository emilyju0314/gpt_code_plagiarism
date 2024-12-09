void ts::GenreDescriptor::DisplayDescriptor(TablesDisplay& display, DID did, const uint8_t* data, size_t size, int indent, TID tid, PDS pds)
{
    if (size > 0) {
        std::ostream& strm(display.duck().out());
        const std::string margin(indent, ' ');

        size_t count = data[0] & 0x1F;
        data++; size--;

        strm << margin << UString::Format(u"Attribute count: %d", {count}) << std::endl;
        while (count > 0 && size > 0) {
            strm << margin << " - Attribute: " << NameFromSection(u"ATSCGenreCode", data[0], names::FIRST) << std::endl;
            data++; size--; count--;
        }
    }

    display.displayExtraData(data, size, indent);
}