void ts::TOT::DisplaySection(TablesDisplay& display, const ts::Section& section, int indent)
{
    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');
    const uint8_t* data = section.payload();
    size_t size = section.payloadSize();

    if (size >= 5) {
        // Fixed part
        Time time;
        DecodeMJD(data, 5, time);
        data += 5; size -= 5;
        strm << margin << "UTC time: " << time.format(Time::DATE | Time::TIME) << std::endl;

        // Descriptor loop
        if (size >= 2) {
            size_t length = GetUInt16(data) & 0x0FFF;
            data += 2; size -= 2;
            if (length > size) {
                length = size;
            }
            display.displayDescriptorList(section, data, length, indent);
            data += length; size -= length;
        }

        // There is a CRC32 at the end of a TOT, even though we are in a short section.
        if (size >= 4) {
            CRC32 comp_crc32(section.content(), data - section.content());
            uint32_t sect_crc32 = GetUInt32(data);
            data += 4; size -= 4;
            strm << margin << UString::Format(u"CRC32: 0x%X ", {sect_crc32});
            if (sect_crc32 == comp_crc32) {
                strm << "(OK)";
            }
            else {
                strm << UString::Format(u"(WRONG, expected 0x%X)", {comp_crc32.value()});
            }
            strm << std::endl;
        }
    }

    display.displayExtraData(data, size, indent);
}