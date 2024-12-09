void ts::LinkageDescriptor::DisplayPrivateINT(TablesDisplay& display, const uint8_t*& data, size_t& size, int indent, uint8_t ltype)
{
    if (size < 1) {
        return;
    }

    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');

    uint8_t data_length = data[0];
    data += 1; size -= 1;
    if (data_length > size) {
        data_length = uint8_t(size);
    }

    while (data_length >= 4) {

        uint32_t plf_id = GetUInt24(data);
        uint8_t loop_length = data[3];
        data += 4; size -= 4; data_length -= 4;
        if (loop_length > data_length) {
            loop_length = data_length;
        }

        strm << margin << UString::Format(u"- Platform id: %s", {ts::names::PlatformId(plf_id, names::HEXA_FIRST)}) << std::endl;

        while (loop_length >= 4) {
            const UString lang(DeserializeLanguageCode(data));
            uint8_t name_length = data[3];
            data += 4; size -= 4;  data_length -= 4; loop_length -= 4;
            if (name_length > loop_length) {
                name_length = loop_length;
            }

            const UString name(display.duck().fromDVB(data, name_length));
            data += name_length; size -= name_length; data_length -= name_length; loop_length -= name_length;

            strm << margin << "  Language: " << lang << ", name: \"" << name << "\"" << std::endl;
        }
    }
}