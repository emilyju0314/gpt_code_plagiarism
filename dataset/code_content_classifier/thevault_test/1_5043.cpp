void ts::CADescriptor::DisplayDescriptor(TablesDisplay& display, DID did, const uint8_t* data, size_t size, int indent, TID tid, PDS pds)
{
    if (size < 4) {
        display.displayExtraData(data, size, indent);
    }
    else {
        std::ostream& strm(display.duck().out());
        const std::string margin(indent, ' ');

        // Extract common part
        uint16_t sysid = GetUInt16(data);
        uint16_t pid = GetUInt16(data + 2) & 0x1FFF;
        const UChar* const dtype = tid == TID_CAT ? u"EMM" : (tid == TID_PMT ? u"ECM" : u"CA");
        data += 4; size -= 4;

        strm << margin << UString::Format(u"CA System Id: %s, %s PID: %d (0x%X)", {names::CASId(sysid, names::FIRST), dtype, pid, pid}) << std::endl;

        // CA private part.
        if (size > 0) {
            // Check if a specific CAS registered its own display routine.
            DisplayCADescriptorFunction disp = TablesFactory::Instance()->getCADescriptorDisplay(sysid);
            if (disp != nullptr) {
                // Use a CAS-specific display routine.
                disp(display, data, size, indent, tid);
            }
            else {
                // Hexa display of the private part.
                strm << margin << "Private CA data:" << std::endl
                     << UString::Dump(data, size, UString::HEXA | UString::ASCII | UString::OFFSET, indent);
            }
        }
    }
}