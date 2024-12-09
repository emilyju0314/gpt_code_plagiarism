void ts::FTAContentManagementDescriptor::DisplayDescriptor(TablesDisplay& display, DID did, const uint8_t* data, size_t size, int indent, TID tid, PDS pds)
{
    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');

    if (size >= 1) {
        strm << margin << UString::Format(u"User-defined: %s", {(data[0] & 0x80) != 0}) << std::endl
             << margin << UString::Format(u"Do not scramble: %s", {(data[0] & 0x08) != 0}) << std::endl
             << margin << UString::Format(u"Access over Internet: %s", {NameFromSection(u"FTARemoteAccessInternet", (data[0] >> 1) & 0x03), names::FIRST}) << std::endl
             << margin << UString::Format(u"Do not apply revocation: %s", {(data[0] & 0x01) != 0}) << std::endl;
        data++; size--;
    }

    display.displayExtraData(data, size, indent);
}