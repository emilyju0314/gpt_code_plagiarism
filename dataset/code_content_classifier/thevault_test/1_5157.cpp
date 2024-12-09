void ts::SHDeliverySystemDescriptor::DisplayDescriptor(TablesDisplay& display, DID did, const uint8_t* data, size_t size, int indent, TID tid, PDS pds)
{
    // Important: With extension descriptors, the DisplayDescriptor() function is called
    // with extension payload. Meaning that data points after descriptor_tag_extension.
    // See ts::TablesDisplay::displayDescriptorData()

    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');

    if (size >= 1) {
        const uint8_t div = (data[0] >> 4) & 0x0F;
        data++; size--;

        strm << margin << UString::Format(u"Diversity mode: 0x%X", {div});
        if ((div & 0x08) != 0) {
            strm << ", paTS";
        }
        if ((div & 0x04) != 0) {
            strm << ", FEC diversity";
        }
        if ((div & 0x02) != 0) {
            strm << ", FEC at phy";
        }
        if ((div & 0x01) != 0) {
            strm << ", FEC at link";
        }
        strm << std::endl;

        while (size >= 3) {
            const uint8_t flags = data[0];
            const uint16_t mval = GetUInt16(data + 1);
            data += 3; size -= 3;

            if ((flags & 0x80) != 0) {
                strm << margin << "- Modulation type: OFDM" << std::endl
                     << margin << UString::Format(u"  Bandwidth: %s", {BandwidthNames.name((mval >> 13) & 0x07)}) << std::endl
                     << margin << UString::Format(u"  Priority: %d", {(mval >> 12) & 0x01}) << std::endl
                     << margin << UString::Format(u"  Constellation & hierarchy: %s", {NameFromSection(u"SHConstellationHierarchy", (mval >> 9) & 0x07, names::FIRST)}) << std::endl
                     << margin << UString::Format(u"  Code rate: %s", {NameFromSection(u"SHCodeRate", (mval >> 5) & 0x0F, names::FIRST)}) << std::endl
                     << margin << UString::Format(u"  Guard interval: %s", {GuardIntervalNames.name((mval >> 3) & 0x03)}) << std::endl
                     << margin << UString::Format(u"  Transmission mode: %s", {TransmissionModeNames.name((mval >> 1) & 0x03)}) << std::endl
                     << margin << UString::Format(u"  Common frequency: %s", {(mval & 0x01) != 0}) << std::endl;
            }
            else {
                const uint8_t symrate = uint8_t(mval >> 1) & 0x1F;
                strm << margin << "- Modulation type: TDM" << std::endl
                     << margin << UString::Format(u"  Polarization: %s", {PolarizationNames.name((mval >> 14) & 0x03)}) << std::endl
                     << margin << UString::Format(u"  Roll off: %s", {RollOffNames.name((mval >> 12) & 0x03)}) << std::endl
                     << margin << UString::Format(u"  Modulation mode: %s", {ModulationNames.name((mval >> 10) & 0x03)}) << std::endl
                     << margin << UString::Format(u"  Code rate: %s", {NameFromSection(u"SHCodeRate", (mval >> 6) & 0x0F, names::FIRST)}) << std::endl
                     << margin << UString::Format(u"  Symbol rate code: 0x%X (%d)", {symrate, symrate}) << std::endl;
            }

            if ((flags & 0x40) != 0) {
                const bool short_interleaver = (flags & 0x20) != 0;
                const size_t min_size = short_interleaver ? 1 : 4;
                if (size < min_size) {
                    break;
                }
                strm << margin << UString::Format(u"  Common multiplier: %d", {(data[0] >> 2) & 0x3F}) << std::endl;
                if (!short_interleaver) {
                    const uint32_t val = GetUInt32(data);
                    strm << margin << UString::Format(u"  Number of late taps: %d", {(val >> 20) & 0x3F}) << std::endl
                         << margin << UString::Format(u"  Number of slices: %d", {(val >> 14) & 0x3F}) << std::endl
                         << margin << UString::Format(u"  Slice distance: %d", {(val >> 6) & 0xFF}) << std::endl
                         << margin << UString::Format(u"  Non-late increments: %d", {val & 0x3F}) << std::endl;
                }
                data += min_size; size -= min_size;
            }
        }
    }

    display.displayExtraData(data, size, indent);
}