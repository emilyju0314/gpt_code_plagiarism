void ts::TransportProtocolDescriptor::DisplayDescriptor(TablesDisplay& display, DID did, const uint8_t* data, size_t size, int indent, TID tid, PDS pds)
{
    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');

    if (size >= 3) {
        const uint16_t proto = GetUInt16(data);
        strm << margin << "Protocol id: " << NameFromSection(u"MHPTransportProtocolId", proto, names::BOTH_FIRST) << std::endl
             << margin << UString::Format(u"Transport protocol label: 0x%X (%d)", {data[2], data[2]}) << std::endl;
        data += 3; size -= 3;

        switch (proto) {
            case MHP_PROTO_CAROUSEL: {
                if (size > 0) {
                    const bool remote = (data[0] & 0x80) != 0;
                    if (remote && size >= 8) {
                        const uint16_t net = GetUInt16(data + 1);
                        const uint16_t ts  = GetUInt16(data + 3);
                        const uint16_t srv = GetUInt16(data + 5);
                        strm << margin << UString::Format(u"Original network id: 0x%X (%d)", {net, net}) << std::endl
                             << margin << UString::Format(u"Transport stream id: 0x%X (%d)", {ts, ts}) << std::endl
                             << margin << UString::Format(u"Service id: 0x%X (%d)", {srv, srv}) << std::endl
                             << margin << UString::Format(u"Component tag: 0x%X (%d)", {data[7], data[7]}) << std::endl;
                        data += 8; size -= 8;
                    }
                    else if (!remote && size >= 2) {
                        strm << margin << UString::Format(u"Component tag: 0x%X (%d)", {data[1], data[1]}) << std::endl;
                        data += 2; size -= 2;
                    }
                }
                break;
            }
            case MHP_PROTO_MPE: {
                if (size > 0) {
                    const bool remote = (data[0] & 0x80) != 0;
                    bool ok = true;
                    if (remote && size >= 8) {
                        const uint16_t net = GetUInt16(data + 1);
                        const uint16_t ts  = GetUInt16(data + 3);
                        const uint16_t srv = GetUInt16(data + 5);
                        strm << margin << UString::Format(u"Original network id: 0x%X (%d)", {net, net}) << std::endl
                             << margin << UString::Format(u"Transport stream id: 0x%X (%d)", {ts, ts}) << std::endl
                             << margin << UString::Format(u"Service id: 0x%X (%d)", {srv, srv}) << std::endl
                             << margin << UString::Format(u"Alignment indicator: %d", {(data[7] >> 7) & 0x01}) << std::endl;
                        data += 8; size -= 8;
                    }
                    else if (!remote && size >= 2) {
                        strm << margin << UString::Format(u"Alignment indicator: %d", {(data[1] >> 7) & 0x01}) << std::endl;
                        data += 2; size -= 2;
                    }
                    else {
                        ok = false;
                    }
                    while (ok && size > 0) {
                        const size_t len = data[0];
                        ok = size >= 1 + len;
                        if (ok) {
                            strm << margin << "URL: \"" << display.duck().fromDVB(data + 1, len) << "\"" << std::endl;
                            data += 1 + len; size -= 1 + len;
                        }
                    }
                }
                break;
            }
            case MHP_PROTO_HTTP: {
                bool ok = true;
                while (ok && size > 0) {
                    const size_t len = data[0];
                    ok = size >= 2 + len;
                    if (ok) {
                        strm << margin << "URL base: \"" << display.duck().fromDVB(data + 1, len) << "\"" << std::endl;
                        size_t count = data[1 + len];
                        data += 2 + len; size -= 2 + len;
                        while (count-- > 0) {
                            const size_t extlen = data[0];
                            ok = size >= 1 + extlen;
                            if (ok) {
                                strm << margin << "  Extension: \"" << display.duck().fromDVB(data + 1, extlen) << "\"" << std::endl;
                                data += 1 + extlen; size -= 1 + extlen;
                            }
                        }
                    }
                }
                break;
            }
            default: {
                strm << margin << UString::Format(u"Selector: %d bytes", {size}) << std::endl;
                if (size > 0) {
                    strm << UString::Dump(data, size, UString::HEXA | UString::ASCII | UString::OFFSET, indent + 2);
                    data += size; size = 0;
                }
            }
        }
    }

    display.displayExtraData(data, size, indent);
}