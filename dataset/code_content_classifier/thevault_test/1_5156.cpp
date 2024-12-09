void ts::C2BundleDeliverySystemDescriptor::DisplayDescriptor(TablesDisplay& display, DID did, const uint8_t* data, size_t size, int indent, TID tid, PDS pds)
{
    // Important: With extension descriptors, the DisplayDescriptor() function is called
    // with extension payload. Meaning that data points after descriptor_tag_extension.
    // See ts::TablesDisplay::displayDescriptorData()

    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');

    while (size >= 8) {

        const uint8_t plp = data[0];
        const uint8_t slice = data[1];
        const uint32_t freq = GetUInt32(data + 2);
        const uint8_t type = (data[6] >> 6) & 0x03;
        const uint8_t duration = (data[6] >> 3) & 0x07;
        const uint8_t guard = data[6] & 0x07;
        const bool master = (data[7] & 0x80) != 0;
        data += 8; size -= 8;

        strm << margin << UString::Format(u"- PLP id: 0x%X (%d), data slice id: 0x%X (%d)", {plp, plp, slice, slice}) << std::endl
             << margin << UString::Format(u"  Frequency: %'d Hz (0x%X)", {freq, freq}) << std::endl
             << margin << UString::Format(u"  Tuning frequency type: %s", {NameFromSection(u"C2TuningType", type, names::FIRST)}) << std::endl
             << margin << UString::Format(u"  Symbol duration: %s", {NameFromSection(u"C2SymbolDuration", duration, names::FIRST)}) << std::endl
             << margin << UString::Format(u"  Guard interval: %d (%s)", {guard, C2DeliverySystemDescriptor::C2GuardIntervalNames.name(guard)}) << std::endl
             << margin << UString::Format(u"  Master channel: %s", {master}) << std::endl;
    }

    display.displayExtraData(data, size, indent);
}