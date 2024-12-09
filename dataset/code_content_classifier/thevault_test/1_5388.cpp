void ts::MosaicDescriptor::DisplayDescriptor(TablesDisplay& display, DID did, const uint8_t* data, size_t size, int indent, TID tid, PDS pds)
{
    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');
    bool ok = size >= 1;

    if (ok) {
        const uint8_t hor = (data[0] >> 4) & 0x07;
        const uint8_t ver = data[0] & 0x07;
        strm << margin << UString::Format(u"Mosaic entry point: %s", {(data[0] & 0x80) != 0}) << std::endl
             << margin << UString::Format(u"Horizontal elementary cells: %d (actual number: %d)", {hor, hor + 1}) << std::endl
             << margin << UString::Format(u"Vertical elementary cells: %d (actual number: %d)", {ver, ver + 1}) << std::endl;
        data++; size--;
    }

    while (ok && size >= 3) {
        const uint8_t id = (data[0] >> 2) & 0x3F;
        const uint8_t pres = data[1] & 0x07;
        size_t len = data[2];
        data += 3; size -= 3;

        strm << margin << UString::Format(u"- Logical cell id: 0x%X (%d)", {id, id}) << std::endl
             << margin << "  Presentation info: " << NameFromSection(u"MosaicLogicalCellPresentation", pres, names::DECIMAL_FIRST) << std::endl;

        ok = size > len;
        if (ok) {
            for (size_t i = 0; i < len; ++i) {
                const uint8_t eid = data[i] & 0x3F;
                strm << margin << UString::Format(u"  Elementary cell id: 0x%X (%d)", {eid, eid}) << std::endl;
            }
            const uint8_t link = data[len];
            strm << margin << "  Cell linkage info: " << NameFromSection(u"MosaicCellLinkageInfo", link, names::DECIMAL_FIRST) << std::endl;
            data += len + 1; size -= len + 1;

            switch (link) {
                case 0x01:
                    ok = size >= 2;
                    if (ok) {
                        strm << margin << UString::Format(u"  Bouquet id: 0x%X (%d)", {GetUInt16(data), GetUInt16(data)}) << std::endl;
                        data += 2; size -= 2;
                    }
                    break;
                case 0x02:
                case 0x03:
                    ok = size >= 6;
                    if (ok) {
                        strm << margin << UString::Format(u"  Original network id: 0x%X (%d)", {GetUInt16(data), GetUInt16(data)}) << std::endl
                             << margin << UString::Format(u"  Transport stream id: 0x%X (%d)", {GetUInt16(data + 2), GetUInt16(data + 2)}) << std::endl
                             << margin << UString::Format(u"  Service id: 0x%X (%d)", {GetUInt16(data + 4), GetUInt16(data + 4)}) << std::endl;
                        data += 6; size -= 6;
                    }
                    break;
                case 0x04:
                    ok = size >= 8;
                    if (ok) {
                        strm << margin << UString::Format(u"  Original network id: 0x%X (%d)", {GetUInt16(data), GetUInt16(data)}) << std::endl
                             << margin << UString::Format(u"  Transport stream id: 0x%X (%d)", {GetUInt16(data + 2), GetUInt16(data + 2)}) << std::endl
                             << margin << UString::Format(u"  Service id: 0x%X (%d)", {GetUInt16(data + 4), GetUInt16(data + 4)}) << std::endl
                             << margin << UString::Format(u"  Event id: 0x%X (%d)", {GetUInt16(data + 6), GetUInt16(data + 6)}) << std::endl;
                        data += 8; size -= 8;
                    }
                    break;
                default:
                    break;
            }
        }
    }

    display.displayExtraData(data, size, indent);
}