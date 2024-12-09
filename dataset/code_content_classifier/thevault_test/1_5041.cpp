void ts::DCCDepartingRequestDescriptor::DisplayDescriptor(TablesDisplay& display, DID did, const uint8_t* data, size_t size, int indent, TID tid, PDS pds)
{
    if (size >= 2) {
        display.duck().out() << UString::Format(u"%*sDCC departing request type: 0x%X (%d)", {indent, u"", data[0], data[0]}) << std::endl;
        const size_t len = data[1];
        data += 2; size -= 2;
        ATSCMultipleString::Display(display, u"DCC departing request text: ", indent, data, size, len);
    }
    display.displayExtraData(data, size, indent);
}