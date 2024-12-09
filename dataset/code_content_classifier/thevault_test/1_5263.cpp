void ts::TargetBackgroundGridDescriptor::DisplayDescriptor(TablesDisplay& display, DID did, const uint8_t* data, size_t size, int indent, TID tid, PDS pds)
{
    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');

    if (size >= 4) {
        const uint32_t x = GetUInt32(data);
        strm << margin
             << UString::Format(u"Size: %dx%d, aspect ratio: %s",
                                {(x >> 18) & 0x3FFF,
                                 (x >> 4) & 0x3FFF,
                                 NameFromSection(u"AspectRatio", x & 0x0F, names::DECIMAL_FIRST)})
             << std::endl;
        data += 4; size -= 4;
    }

    display.displayExtraData(data, size, indent);
}