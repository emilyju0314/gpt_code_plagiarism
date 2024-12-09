void ts::SpliceInformationTable::DisplaySection(TablesDisplay& display, const ts::Section& section, int indent)
{
    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');
    const uint8_t* data = section.payload();
    size_t size = section.payloadSize();

    // Payload layout: fixed part (11 bytes), variable part, CRC2 (4 bytes).
    // There is a CRC32 at the end of a SpliceInformationTable, even though we are in a short section.

    if (size < 15) {
        display.displayExtraData(data, size, indent);
        return;
    }

    // Check CRC32 now, display it later.
    const CRC32 comp_crc32(section.content(), section.size() - 4);
    const uint32_t sect_crc32 = GetUInt32(data + size - 4);
    size -= 4;

    // Fixed part
    const uint8_t protocol_version = data[0];
    const uint8_t encrypted_packet = (data[1] >> 7) & 0x01;
    const uint8_t encryption_algo = (data[1] >> 1) & 0x3F;
    const uint64_t pts_adjustment = (uint64_t(data[1] & 0x01) << 32) | uint64_t(GetUInt32(data + 2));
    const uint8_t cw_index = data[6];
    const uint16_t tier = (GetUInt16(data + 7) >> 4) & 0x0FFF;
    size_t cmd_length = GetUInt16(data + 8) & 0x0FFF;
    const uint8_t cmd_type = data[10];
    data += 11; size -= 11;

    strm << margin << UString::Format(u"Protocol version: 0x%X (%d)", {protocol_version, protocol_version}) << std::endl
         << margin << "Encryption: ";
    if (encrypted_packet == 0) {
        strm << "none";
    }
    else {
        strm << UString::Format(u"0x%X (%d)", {encryption_algo, encryption_algo});
        switch (encryption_algo) {
            case 0: strm << ", none"; break;
            case 1: strm << ", DES-ECB"; break;
            case 2: strm << ", DES-CBC"; break;
            case 3: strm << ", TDES-ECB"; break;
            default: break;
        }
    }
    strm << std::endl
         << margin << UString::Format(u"PTS adjustment: 0x%09X (%d)", {pts_adjustment, pts_adjustment}) << std::endl
         << margin << UString::Format(u"CW index: 0x%X (%d), tier: 0x%03X (%d)", {cw_index, cw_index, tier, tier}) << std::endl;

    if (encrypted_packet) {
        // The encrypted part starts at the command type.
        strm << margin << "Encrypted command, cannot display" << std::endl;
    }
    else {
        // Unencrypted packet, can display everything.
        strm << margin << UString::Format(u"Command type: %s, size: %d bytes", {NameFromSection(u"SpliceCommandType", cmd_type, names::HEXA_FIRST), cmd_length}) << std::endl;

        // Display the command body. Format some commands, simply dump others.
        if (cmd_length > size) {
            cmd_length = size;
        }
        switch (cmd_type) {
            case SPLICE_SCHEDULE: {
                SpliceSchedule cmd;
                const int done = cmd.deserialize(data, cmd_length);
                if (done >= 0) {
                    assert(size_t(done) <= cmd_length);
                    cmd.display(display, indent);
                    data += done; size -= done; cmd_length -= done;
                }
                break;
            }
            case SPLICE_INSERT: {
                SpliceInsert cmd;
                const int done = cmd.deserialize(data, cmd_length);
                if (done >= 0) {
                    assert(size_t(done) <= cmd_length);
                    cmd.display(display, indent);
                    data += done; size -= done; cmd_length -= done;
                }
                break;
            }
            case SPLICE_TIME_SIGNAL: {
                SpliceTime cmd;
                const int done = cmd.deserialize(data, cmd_length);
                if (done >= 0) {
                    strm << margin << "Time: " << cmd.toString() << std::endl;
                    data += done; size -= done; cmd_length -= done;
                }
                break;
            }
            case SPLICE_PRIVATE_COMMAND: {
                if (cmd_length >= 4) {
                    const uint32_t cmd = GetUInt32(data);
                    strm << margin << UString::Format(u"Command identifier: 0x%0X (%'d)", {cmd, cmd}) << std::endl;
                    data += 4; size -= 4; cmd_length -= 4;
                }
                break;
            }
            default:
                // Invalid command.
                break;
        }
        if (cmd_length > 0) {
            // Unexpected command or unexpected command size.
            strm << margin << "Remaining command content:" << std::endl
                 << UString::Dump(data, cmd_length, UString::HEXA | UString::ASCII | UString::OFFSET, indent + 2);
        }
        data += cmd_length; size -= cmd_length;

        // Splice descriptors.
        if (size >= 2) {
            size_t dl_length = GetUInt16(data);
            data += 2; size -= 2;
            if (dl_length > size) {
                dl_length = size;
            }
            display.displayDescriptorList(section, data, dl_length, indent);
            data += dl_length; size -= dl_length;
        }
    }

    // Final CRC32
    strm << margin << UString::Format(u"CRC32: 0x%X ", {sect_crc32});
    if (sect_crc32 == comp_crc32) {
        strm << "(OK)";
    }
    else {
        strm << UString::Format(u"(WRONG, expected 0x%X)", {comp_crc32.value()});
    }
    strm << std::endl;
}