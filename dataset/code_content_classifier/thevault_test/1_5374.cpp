void ts::S2XSatelliteDeliverySystemDescriptor::DisplayDescriptor(TablesDisplay& display, DID did, const uint8_t* data, size_t size, int indent, TID tid, PDS pds)
{
    // Important: With extension descriptors, the DisplayDescriptor() function is called
    // with extension payload. Meaning that data points after descriptor_tag_extension.
    // See ts::TablesDisplay::displayDescriptorData()

    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');
    bool ok = true;

    if (size >= 2) {
        const uint8_t profiles = (data[0] >> 3) & 0x1F;
        strm << margin << UString::Format(u"Receiver profiles: 0x%X", {profiles});
        if ((profiles & 0x01) != 0) {
            strm << ", broadcast services";
        }
        if ((profiles & 0x02) != 0) {
            strm << ", interactive services";
        }
        if ((profiles & 0x04) != 0) {
            strm << ", DSNG";
        }
        if ((profiles & 0x08) != 0) {
            strm << ", professional services";
        }
        if ((profiles & 0x10) != 0) {
            strm << ", VL-SNR";
        }
        const uint8_t mode = (data[1] >> 6) & 0x03;
        const bool sseq_sel = (data[1] & 0x20) != 0;
        strm << std::endl
             << margin << "S2X mode: " << NameFromSection(u"S2XMode", mode, names::FIRST) << std::endl
             << margin << "TS/GS S2X mode: " << NameFromSection(u"TSGSS2XMode", data[1] & 0x03, names::FIRST) << std::endl;
        data += 2; size -= 2;

        if (ok && sseq_sel) {
            ok = size >= 3;
            if (ok) {
                strm << margin << UString::Format(u"Scrambling sequence index: 0x%05X", { GetUInt24(data) & 0x03FFFF }) << std::endl;
                data += 3; size -= 3;
            }
        }
        ok = ok && DisplayChannel(display, u"Master channel", data, size, indent);
        if (ok && mode == 2) {
            ok = size >= 1;
            if (ok) {
                strm << margin << UString::Format(u"Timeslice number: 0x%X (%d)", {data[0], data[0]}) << std::endl;
                data++; size--;
            }
        }
        if (ok && mode == 3) {
            ok = size >= 1;
            if (ok) {
                const bool num = (data[0] & 0x01) != 0;
                data++; size--;
                ok = DisplayChannel(display, u"Channel bond 0", data, size, indent) &&
                    (!num || DisplayChannel(display, u"Channel bond 1", data, size, indent));
            }
        }

        if (size > 0) {
            strm << margin << "Reserved for future use: " << size << " bytes:" << std::endl
                 << UString::Dump(data, size, UString::HEXA | UString::ASCII | UString::OFFSET, indent);
            data += size; size = 0;
        }
    }

    display.displayExtraData(data, size, indent);
}