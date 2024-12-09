void ts::StereoscopicProgramInfoDescriptor::DisplayDescriptor(TablesDisplay& display, DID did, const uint8_t* data, size_t size, int indent, TID tid, PDS pds)
{
    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');

    if (size >= 1) {
        strm << margin << "Stereoscopic service type: " << NameFromSection(u"StereoscopicServiceType", data[0] & 0x07, names::DECIMAL_FIRST) << std::endl;
        data += 1; size -= 1;
    }

    display.displayExtraData(data, size, indent);
}