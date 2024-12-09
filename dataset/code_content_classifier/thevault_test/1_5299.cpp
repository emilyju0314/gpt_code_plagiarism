void ts::DataBroadcastIdDescriptor::DisplaySelectorSSU(TablesDisplay& display, const uint8_t*& data, size_t& size, int indent, uint16_t dbid)
{
    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');

    // OUI_data_length:
    if (size < 1) {
        return;
    }
    uint8_t dlength = data[0];
    data += 1; size -= 1;
    if (dlength > size) {
        dlength = uint8_t(size);
    }

    // OUI loop:
    while (dlength >= 6) {
        // Get fixed part (6 bytes)
        uint32_t oui = GetUInt32(data - 1) & 0x00FFFFFF; // 24 bits
        uint8_t upd_type = data[3] & 0x0F;
        uint8_t upd_flag = (data[4] >> 5) & 0x01;
        uint8_t upd_version = data[4] & 0x1F;
        uint8_t slength = data[5];
        data += 6; size -= 6; dlength -= 6;
        // Get variable-length selector
        const uint8_t* sdata = data;
        if (slength > dlength) {
            slength = dlength;
        }
        data += slength; size -= slength; dlength -= slength;
        // Display
        strm << margin << "OUI: " << names::OUI(oui, names::FIRST) << std::endl
            << margin << UString::Format(u"  Update type: 0x%X (", {upd_type});
        switch (upd_type) {
            case 0x00: strm << "proprietary update solution"; break;
            case 0x01: strm << "standard update carousel (no notification) via broadcast"; break;
            case 0x02: strm << "system software update with UNT via broadcast"; break;
            case 0x03: strm << "system software update using return channel with UNT"; break;
            default:   strm << "reserved"; break;
        }
        strm << ")" << std::endl << margin << "  Update version: ";
        if (upd_flag == 0) {
            strm << "none";
        }
        else {
            strm << UString::Format(u"%d (0x%02X)", {upd_version, upd_version});
        }
        strm << std::endl;
        if (slength > 0) {
            strm << margin << "  Selector data:" << std::endl
                << UString::Dump(sdata, slength, UString::HEXA | UString::ASCII, indent + 2);
        }
    }

    // Extraneous data in OUI_loop:
    if (dlength > 0) {
        strm << margin << "Extraneous data in OUI loop:" << std::endl
             << UString::Dump(data, dlength, UString::HEXA | UString::ASCII, indent);
        data += dlength; size -= dlength;
    }

    // Private data
    if (size > 0) {
        strm << margin << "Private data:" << std::endl
             << UString::Dump(data, size, UString::HEXA | UString::ASCII, indent);
        data += size; size = 0;
    }
}