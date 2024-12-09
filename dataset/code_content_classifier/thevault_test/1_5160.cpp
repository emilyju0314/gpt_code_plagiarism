void ts::SupplementaryAudioDescriptor::DisplayDescriptor(TablesDisplay& display, DID did, const uint8_t* data, size_t size, int indent, TID tid, PDS pds)
{
    // Important: With extension descriptors, the DisplayDescriptor() function is called
    // with extension payload. Meaning that data points after descriptor_tag_extension.
    // See ts::TablesDisplay::displayDescriptorData()

    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');

    if (size >= 1) {
        const uint8_t mix_type = (data[0] >> 7) & 0x01;
        const uint8_t editorial = (data[0] >> 2) & 0x1F;
        const uint8_t lang_present = data[0] & 0x01;
        data++; size--;
        strm << margin << "Mix type: ";
        switch (mix_type) {
            case 0:  strm << "supplementary stream"; break;
            case 1:  strm << "complete and independent stream"; break;
            default: assert(false);
        }
        strm << std::endl << margin << "Editorial classification: ";
        switch (editorial) {
            case 0x00: strm << "main audio"; break;
            case 0x01: strm << "audio description for the visually impaired"; break;
            case 0x02: strm << "clean audio for the hearing impaired"; break;
            case 0x03: strm << "spoken subtitles for the visually impaired"; break;
            default:   strm << UString::Format(u"reserved value 0x%X", {editorial}); break;
        }
        strm << std::endl;
        if (lang_present && size >= 3) {
            strm << margin << "Language: " << DeserializeLanguageCode(data) << std::endl;
            data += 3; size -= 3;
        }
        if (size > 0) {
            strm << margin << "Private data:" << std::endl
                 << UString::Dump(data, size, UString::HEXA | UString::ASCII | UString::OFFSET, indent);
            data += size; size = 0;
        }
    }

    display.displayExtraData(data, size, indent);
}