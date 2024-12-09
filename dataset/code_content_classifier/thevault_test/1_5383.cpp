void ts::SSUSubgroupAssociationDescriptor::DisplayDescriptor(TablesDisplay& display, DID did, const uint8_t* data, size_t size, int indent, TID tid, PDS pds)
{
    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');

    if (size >= 5) {
        const uint64_t tag = GetUInt40(data);
        strm << margin << UString::Format(u"Subgroup tag: 0x%010X (%d)", {tag, tag}) << std::endl;
        data += 5; size -= 5;
    }

    display.displayExtraData(data, size, indent);
}