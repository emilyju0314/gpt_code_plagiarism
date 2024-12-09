bool ts::TransportProtocolDescriptor::transferSelectorBytes(DuckContext& duck)
{
    // Clear other protocols.
    carousel.clear();
    mpe.clear();
    http.clear();

    // Build one selected protocol by analyzing the selector bytes.
    const uint8_t* data = selector.data();
    size_t size = selector.size();

    switch (protocol_id) {
        case MHP_PROTO_CAROUSEL: {
            if (size == 0) {
                return false;
            }
            const bool remote = (data[0] & 0x80) != 0;
            if ((remote && size != 8) || (!remote && size != 2)) {
                return false;
            }
            if (remote) {
                carousel.original_network_id = GetUInt16(data + 1);
                carousel.transport_stream_id = GetUInt16(data + 3);
                carousel.service_id = GetUInt16(data + 5);
                carousel.component_tag = data[7];
            }
            else {
                carousel.component_tag = data[1];
            }
            break;
        }
        case MHP_PROTO_MPE: {
            if (size == 0) {
                return false;
            }
            const bool remote = (data[0] & 0x80) != 0;
            if ((remote && size < 8) || (!remote && size < 2)) {
                return false;
            }
            data++; size--;
            if (remote) {
                mpe.original_network_id = GetUInt16(data);
                mpe.transport_stream_id = GetUInt16(data + 2);
                mpe.service_id = GetUInt16(data + 4);
                data += 6; size -= 6;
            }
            mpe.alignment_indicator = (data[0] & 0x80) != 0;
            data++; size--;
            while (size > 0) {
                const size_t len = data[0];
                if (size < 1 + len) {
                    return false;
                }
                mpe.urls.push_back(duck.fromDVB(data + 1, len));
                data += 1 + len; size -= 1 + len;
            }
            break;
        }
        case MHP_PROTO_HTTP: {
            while (size > 0) {
                // Deserialize one URL entry.
                HTTPEntry e;
                // Get URL base.
                const size_t len = data[0];
                if (size < 2 + len) {
                    return false;
                }
                e.URL_base = duck.fromDVB(data + 1, len);
                size_t count = data[1 + len];
                data += 2 + len; size -= 2 + len;
                // Loop on all URL extensions.
                while (count-- > 0) {
                    if (size == 0) {
                        return false;
                    }
                    const size_t extlen = data[0];
                    if (size < 1 + extlen) {
                        return false;
                    }
                    e.URL_extensions.push_back(duck.fromDVB(data + 1, extlen));
                    data += 1 + extlen; size -= 1 + extlen;
                }
                // URL entry completed.
                http.push_back(e);
            }
            break;
        }
        default: {
            // Other protocols, do not interpret, keep selector byte array.
            return true;
        }
    }

    // When a protocol was built, clear the selector byte array.
    selector.clear();
    return true;
}