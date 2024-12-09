void ts::HEVCVideoDescriptor::DisplayDescriptor(TablesDisplay& display, DID did, const uint8_t* data, size_t size, int indent, TID tid, PDS pds)
{
    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');

    if (size >= 13) {

        const int profile_space = (data[0] >> 6) & 0x03;
        const bool tier = (data[0] & 0x20) != 0;
        const int profile_idc = data[0] & 0x1F;
        const uint32_t profile_compatibility_indication = GetUInt32(data + 1);
        const bool progressive_source = (data[5] & 0x80) != 0;
        const bool interlaced_source = (data[5] & 0x40) != 0;
        const bool non_packed_constraint = (data[5] & 0x20) != 0;
        const bool frame_only_constraint = (data[5] & 0x10) != 0;
        const uint64_t copied_44bits = (uint64_t(GetUInt16(data + 5) & 0x0FFF) << 32) | GetUInt32(data + 7);
        const int level_idc = data[11];
        const bool temporal = (data[12] & 0x80) != 0;
        const bool HEVC_still_present = (data[12] & 0x40) != 0;
        const bool HEVC_24hr_picture_present = (data[12] & 0x20) != 0;
        const bool sub_pic_hrd_params_not_present = (data[12] & 0x10) != 0;
        const uint8_t HDR_WCG_idc = data[12] & 0x03;
        data += 13; size -= 13;

        strm << margin << "Profile space: " << profile_space
             << ", tier: " << UString::TrueFalse(tier)
             << ", profile IDC: " << profile_idc
             << std::endl
             << margin << "Profile compatibility: " << UString::Hexa(profile_compatibility_indication)
             << std::endl
             << margin << "Progressive source: " << UString::TrueFalse(progressive_source)
             << ", interlaced source: " << UString::TrueFalse(interlaced_source)
             << ", non packed: " << UString::TrueFalse(non_packed_constraint)
             << ", frame only: " << UString::TrueFalse(frame_only_constraint)
             << std::endl
             << margin << "Copied 44 bits: " << UString::Hexa(copied_44bits, 11)
             << std::endl
             << margin << "Level IDC: " << level_idc
             << ", still pictures: " << UString::TrueFalse(HEVC_still_present)
             << ", 24-hour pictures: " << UString::TrueFalse(HEVC_24hr_picture_present)
             << std::endl
             << margin << "No sub-pic HRD params: " << UString::TrueFalse(sub_pic_hrd_params_not_present)
             << ", HDR WCG idc: " << UString::Decimal(HDR_WCG_idc)
             << std::endl;

        if (temporal && size >= 2) {
            strm << margin << "Temporal id min: " << int(data[0] >> 5) << ", max: " << int(data[1] >> 5) << std::endl;
            data += 2; size -= 2;
        }
    }

    display.displayExtraData(data, size, indent);
}