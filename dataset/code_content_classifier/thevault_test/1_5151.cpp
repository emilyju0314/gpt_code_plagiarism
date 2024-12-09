void ts::TelephoneDescriptor::DisplayDescriptor(TablesDisplay& display, DID did, const uint8_t* data, size_t size, int indent, TID tid, PDS pds)
{
    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');

    if (size >= 3) {
        const uint8_t ctype = data[0] & 0x1F;
        strm << margin << UString::Format(u"Foreign availability: %s", {(data[0] & 0x20) != 0}) << std::endl
             << margin << UString::Format(u"Connection type: 0x%X (%d)", {ctype, ctype}) << std::endl;
        const size_t country_len = (data[1] >> 5) & 0x03;
        const size_t inter_len = (data[1] >> 2) & 0x07;
        const size_t oper_len = data[1] & 0x03;
        const size_t nat_len = (data[2] >> 4) & 0x07;
        const size_t core_len = data[2] & 0x0F;
        data += 3; size -= 3;

        UString str;
        if (size >= country_len && DVBCharsetSingleByte::ISO_8859_1.decode(str, data, country_len)) {
            data += country_len; size -= country_len;
            strm << margin << "Country prefix: \"" << str << "\"" << std::endl;

            if (size >= inter_len && DVBCharsetSingleByte::ISO_8859_1.decode(str, data, inter_len)) {
                data += inter_len; size -= inter_len;
                strm << margin << "International area code: \"" << str << "\"" << std::endl;

                if (size >= oper_len && DVBCharsetSingleByte::ISO_8859_1.decode(str, data, oper_len)) {
                    data += oper_len; size -= oper_len;
                    strm << margin << "Operator code: \"" << str << "\"" << std::endl;

                    if (size >= nat_len && DVBCharsetSingleByte::ISO_8859_1.decode(str, data, nat_len)) {
                        data += nat_len; size -= nat_len;
                        strm << margin << "National area code: \"" << str << "\"" << std::endl;

                        if (size >= core_len && DVBCharsetSingleByte::ISO_8859_1.decode(str, data, core_len)) {
                            data += core_len; size -= core_len;
                            strm << margin << "Core number: \"" << str << "\"" << std::endl;
                        }
                    }
                }
            }
        }
    }

    display.displayExtraData(data, size, indent);
}