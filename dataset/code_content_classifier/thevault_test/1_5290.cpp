void ts::HierarchyDescriptor::DisplayDescriptor(TablesDisplay& display, DID did, const uint8_t* data, size_t size, int indent, TID tid, PDS pds)
{
    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');

    if (size >= 4) {
        strm << margin << "Temporal scalability: " << UString::TrueFalse((data[0] & 0x40) != 0) << std::endl
             << margin << "Spatial scalability: " << UString::TrueFalse((data[0] & 0x20) != 0) << std::endl
             << margin << "Quality scalability: " << UString::TrueFalse((data[0] & 0x10) != 0) << std::endl
             << margin << "Hierarchy type: " << NameFromSection(u"HierarchyType", data[0] & 0x0F, names::BOTH_FIRST) << std::endl
             << margin << UString::Format(u"Hierarchy layer index: %d", {data[1] & 0x3F}) << std::endl
             << margin << "Tref present: " << UString::TrueFalse((data[2] & 0x80) != 0) << std::endl
             << margin << UString::Format(u"Hierarchy embedded layer index: %d", {data[2] & 0x3F}) << std::endl
             << margin << UString::Format(u"Hierarchy channel: %d", {data[3] & 0x3F}) << std::endl;
        data += 4; size -= 4;
    }

    display.displayExtraData(data, size, indent);
}