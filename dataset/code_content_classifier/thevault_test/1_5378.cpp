void ts::TargetSmartcardDescriptor::DisplayDescriptor(TablesDisplay& display, DID did, const uint8_t* data, size_t size, int indent, TID tid, PDS pds)
{
    if (size >= 4) {
        const uint32_t id = GetUInt32(data);
        display.duck().out() << UString::Format(u"%*sSuper CAS Id: 0x%X (%d)", {indent, u"", id, id})
                      << std::endl
                      << UString::Format(u"%*sPrivate data (%d bytes): %s", {indent, u"", size - 4, UString::Dump(data + 4, size - 4, UString::SINGLE_LINE)})
                      << std::endl;
    }
    else {
        display.displayExtraData(data, size, indent);
    }
}