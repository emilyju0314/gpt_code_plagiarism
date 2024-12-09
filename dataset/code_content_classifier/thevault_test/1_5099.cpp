void ts::GraphicsConstraintsDescriptor::DisplayDescriptor(TablesDisplay& display, DID did, const uint8_t* data, size_t size, int indent, TID tid, PDS pds)
{
    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');

    if (size >= 1) {
        strm << margin << "Can run without visible UI: " << UString::TrueFalse((data[0] & 0x04) != 0) << std::endl
             << margin << "Handles configuration changed: " << UString::TrueFalse((data[0] & 0x02) != 0) << std::endl
             << margin << "Handles externally controlled video: " << UString::TrueFalse((data[0] & 0x01) != 0) << std::endl;
        if (size > 1) {
            strm << margin << "Graphics configuration bytes:" << std::endl
                 << UString::Dump(data + 1, size -1, UString::HEXA | UString::ASCII, indent + 2);
        }
        size = 0;
    }

    display.displayExtraData(data, size, indent);
}