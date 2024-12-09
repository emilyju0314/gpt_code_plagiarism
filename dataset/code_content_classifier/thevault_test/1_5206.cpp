void ts::AnnouncementSupportDescriptor::DisplayDescriptor(TablesDisplay& display, DID did, const uint8_t* data, size_t size, int indent, TID tid, PDS pds)
{
    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');

    if (size >= 2) {
        // Get announcement_support_indicator.
        // We will check later that all annoucement types are present.
        uint16_t indicator = GetUInt16(data);
        data += 2; size -= 2;
        strm << margin << UString::Format(u"Annoucement support indicator: 0x%X", {indicator}) << std::endl;

        // List all entries.
        while (size >= 1) {
            const uint8_t type = (data[0] >> 4) & 0x0F;
            const uint8_t ref = data[0] & 0x07;
            data++; size--;

            // Clear types one by one in announcement_support_indicator.
            indicator &= ~uint16_t(1 << type);

            strm << margin << "- Announcement type: " << NameFromSection(u"AnnouncementType", type, names::DECIMAL_FIRST) << std::endl
                 << margin << "  Reference type: " << NameFromSection(u"AnnouncementReferenceType", ref, names::DECIMAL_FIRST) << std::endl;
            if (ref >= 1 && ref <= 3) {
                if (size < 7) {
                    break;
                }
                strm << margin << UString::Format(u"  Original network id: 0x%X (%d)", {GetUInt16(data), GetUInt16(data)}) << std::endl
                     << margin << UString::Format(u"  Transport stream id: 0x%X (%d)", {GetUInt16(data + 2), GetUInt16(data + 2)}) << std::endl
                     << margin << UString::Format(u"  Service id: 0x%X (%d)", {GetUInt16(data + 4), GetUInt16(data + 4)}) << std::endl
                     << margin << UString::Format(u"  Component tag: 0x%X (%d)", {data[6], data[6]}) << std::endl;
                data += 7; size -= 7;
            }
        }

        // List missing types.
        for (uint8_t type = 0; indicator != 0 && type < 16; ++type) {
            const uint16_t mask = uint16_t(1 << type);
            if ((indicator & mask) != 0) {
                indicator &= ~mask;
                strm << margin << "- Missing announcement type: " << NameFromSection(u"AnnouncementType", type, names::DECIMAL_FIRST) << std::endl;
            }
        }
    }

    display.displayExtraData(data, size, indent);
}