int ts::SpliceSchedule::deserialize(const uint8_t* data, size_t size)
{
    const uint8_t* const start = data;
    clear();

    if (size < 1) {
        return -1; // too short
    }

    // Numbere of splice events
    uint8_t spliceCount = data[0];
    data += 1; size -= 1;

    while (spliceCount > 0) {
        // Decode one event.
        Event ev;

        ev.event_id = GetUInt32(data);
        ev.canceled = (data[4] & 0x80) != 0;
        data += 5; size -= 5;

        if (!ev.canceled) {
            if (size < 1) {
                return -1; // too short
            }

            ev.splice_out = (data[0] & 0x80) != 0;
            ev.program_splice = (data[0] & 0x40) != 0;
            ev.use_duration = (data[0] & 0x20) != 0;
            data++; size--;

            if (ev.program_splice) {
                // The complete program switches at a given time.
                if (size < 4) {
                    return -1; // too short
                }
                ev.program_utc = GetUInt32(data);
                data += 4; size -= 4;
            }
            else {
                // Program components switch individually.
                if (size < 1) {
                    return -1; // too short
                }
                size_t count = data[0];
                data++; size--;
                while (count-- > 0) {
                    if (size < 5) {
                        return -1; // too short
                    }
                    ev.components_utc.insert(std::make_pair(GetUInt8(data), GetUInt32(data + 1)));
                    data += 5; size -= 5;
                }
            }
            if (ev.use_duration) {
                if (size < 5) {
                    return -1; // too short
                }
                ev.auto_return = (data[0] & 0x80) != 0;
                ev.duration_pts = (uint64_t(data[0] & 0x01) << 32) | uint64_t(GetUInt32(data + 1));
                data += 5; size -= 5;
            }
            if (size < 4) {
                return -1; // too short
            }
            ev.program_id = GetUInt16(data);
            ev.avail_num = data[2];
            ev.avails_expected = data[3];
            data += 4; size -= 4;
        }

        // Finally add the deserialized event in the list.
        events.push_back(ev);
        spliceCount--;
    }

    _is_valid = true;
    return int(data - start);
}