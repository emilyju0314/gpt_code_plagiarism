void ts::TargetSerialNumberDescriptor::DisplayDescriptor(TablesDisplay& display, DID did, const uint8_t* data, size_t size, int indent, TID tid, PDS pds)
{
    display.duck().out() << margin
                  << UString::Format(u"%*sSerial number (%d bytes): %s", {indent, u"", size, UString::Dump(data, size, UString::SINGLE_LINE)})
                  << std::endl;
}