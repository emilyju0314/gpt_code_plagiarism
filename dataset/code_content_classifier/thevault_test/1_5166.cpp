void ts::AVCVideoDescriptor::DisplayDescriptor(TablesDisplay& display, DID did, const uint8_t* data, size_t size, int indent, TID tid, PDS pds)
{
    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');

    if (size >= 4) {
        const uint8_t profile_idc = data[0];
        const bool constraint_set0 = (data[1] & 0x80) != 0;
        const bool constraint_set1 = (data[1] & 0x40) != 0;
        const bool constraint_set2 = (data[1] & 0x20) != 0;
        const uint8_t AVC_compatible_flags = data[1] & 0x1F;
        const uint8_t level_idc = data[2];
        const bool AVC_still_present = (data[3] & 0x80) != 0;
        const bool AVC_24_hour_picture = (data[3] & 0x40) != 0;
        data += 4; size -= 4;

        strm << margin << "Profile IDC: " << int(profile_idc)
             << ", level IDC: " << int(level_idc)
             << std::endl
             << margin << "Constraint set0: " << UString::TrueFalse(constraint_set0)
             << ", set1: " << UString::TrueFalse(constraint_set1)
             << ", set2: " << UString::TrueFalse(constraint_set2)
             << ", AVC compatible flags: " << UString::Hexa(AVC_compatible_flags)
             << std::endl
             << margin << "Still pictures: " << UString::TrueFalse(AVC_still_present)
             << ", 24-hour pictures: " << UString::TrueFalse(AVC_24_hour_picture)
             << std::endl;
    }

    display.displayExtraData(data, size, indent);
}