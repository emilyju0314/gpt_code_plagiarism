void ts::ATSCEAC3AudioDescriptor::DisplayDescriptor(TablesDisplay& display, DID did, const uint8_t* data, size_t size, int indent, TID tid, PDS pds)
{
    if (size >= 2) {

        std::ostream& strm(display.duck().out());
        const std::string margin(indent, ' ');

        // Fixed initial size: 2 bytes.
        const bool bsid_flag = (data[0] & 0x40) != 0;
        const bool mainid_flag = (data[0] & 0x20) != 0;
        const bool asvc_flag = (data[0] & 0x10) != 0;
        const bool mixinfo = (data[0] & 0x08) != 0;
        const bool sub1_flag = (data[0] & 0x04) != 0;
        const bool sub2_flag = (data[0] & 0x02) != 0;
        const bool sub3_flag = (data[0] & 0x01) != 0;
        const bool full = (data[1] & 0x40) != 0;
        const uint8_t svc_type = (data[1] >> 3) & 0x07;
        const uint8_t channels = data[1] & 0x07;
        const bool lang_flag = size > 2 && (data[2] & 0x80) != 0;   // in next byte
        const bool lang2_flag = size > 2 && (data[2] & 0x40) != 0;  // in next byte
        data += 2; size -= 2;

        strm << margin << UString::Format(u"Mixinfo exists: %s", {mixinfo}) << std::endl
             << margin << UString::Format(u"Full service: %s", {full}) << std::endl
             << margin << UString::Format(u"Audio service type: %s", {NameFromSection(u"EAC3AudioServiceType", svc_type, names::VALUE)}) << std::endl
             << margin << UString::Format(u"Num. channels: %s", {NameFromSection(u"ATSCEAC3NumChannels", channels, names::VALUE)}) << std::endl;

        if (size > 0) {
            if (bsid_flag) {
                const uint8_t id = data[0] & 0x1F;
                strm << margin << UString::Format(u"Bit stream id (bsid): 0x%X (%d)", {id, id}) << std::endl;
            }
            data++; size--;
        }
        if (mainid_flag && size > 0) {
            const uint8_t id = data[0] & 0x07;
            strm << margin << UString::Format(u"Priority: %d", {(data[0] >> 3) & 0x03}) << std::endl
                 << margin << UString::Format(u"Main id: 0x%X (%d)", {id, id}) << std::endl;
            data++; size--;
        }
        if (asvc_flag && size > 0) {
            strm << margin << UString::Format(u"Associated service (asvc): 0x%X (%d)", {data[0], data[0]}) << std::endl;
            data++; size--;
        }
        if (sub1_flag && size > 0) {
            strm << margin << UString::Format(u"Substream 1: 0x%X (%d)", {data[0], data[0]}) << std::endl;
            data++; size--;
        }
        if (sub2_flag && size > 0) {
            strm << margin << UString::Format(u"Substream 2: 0x%X (%d)", {data[0], data[0]}) << std::endl;
            data++; size--;
        }
        if (sub3_flag && size > 0) {
            strm << margin << UString::Format(u"Substream 3: 0x%X (%d)", {data[0], data[0]}) << std::endl;
            data++; size--;
        }
        if (lang_flag && size >= 3) {
            strm << margin << "Language: \"" << DeserializeLanguageCode(data) << "\"" << std::endl;
            data += 3; size -= 3;
        }
        if (lang2_flag && size >= 3) {
            strm << margin << "Language 2: \"" << DeserializeLanguageCode(data) << "\"" << std::endl;
            data += 3; size -= 3;
        }
        if (sub1_flag && size >= 3) {
            strm << margin << "Substream 1 language: \"" << DeserializeLanguageCode(data) << "\"" << std::endl;
            data += 3; size -= 3;
        }
        if (sub2_flag && size >= 3) {
            strm << margin << "Substream 2 language: \"" << DeserializeLanguageCode(data) << "\"" << std::endl;
            data += 3; size -= 3;
        }
        if (sub3_flag && size >= 3) {
            strm << margin << "Substream 3 language: \"" << DeserializeLanguageCode(data) << "\"" << std::endl;
            data += 3; size -= 3;
        }
        if (size > 0) {
            strm << margin << "Additional information:" << std::endl
                 << UString::Dump(data, size, UString::HEXA | UString::ASCII | UString::OFFSET, indent);
            data += size; size = 0;
        }
    }

    display.displayExtraData(data, size, indent);
}