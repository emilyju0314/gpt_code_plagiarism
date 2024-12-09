void ts::SSUEnhancedMessageDescriptor::DisplayDescriptor(TablesDisplay& display, DID did, const uint8_t* data, size_t size, int indent, TID tid, PDS pds)
{
    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');

    if (size >= 5) {
        strm << margin << UString::Format(u"Descriptor number: %d, last: %d", {(data[0] >> 4) & 0x0F, data[0] & 0x0F}) << std::endl
             << margin << "Language: " << DeserializeLanguageCode(data + 1) << std::endl
             << margin << UString::Format(u"Message index: %d", {data[4] & 0x1F}) << std::endl
             << margin << "Text: \"" << display.duck().fromDVB(data + 5, size - 5) << "\"" << std::endl;
    }
    else {
        display.displayExtraData(data, size, indent);
    }
}