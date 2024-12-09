void ts::AbstractTransportListTable::addSection(BinaryTable& table,
                                                int& section_number,
                                                uint8_t* payload,
                                                uint8_t*& tsll_addr,
                                                uint8_t*& data,
                                                size_t& remain) const
{
    // Update transport_stream_loop_length in current section
    PutUInt16(tsll_addr, 0xF000 | uint16_t(data - tsll_addr - 2));

    // Add current section, open a new one
    addSection(table, section_number, payload, data, remain);

    // Insert a zero-length global descriptor loop
    assert(remain >= 4);
    PutUInt16(data, 0xF000);

    // Reserve transport_stream_loop_length.
    tsll_addr = data + 2;
    PutUInt16(data + 2, 0xF000);
    data += 4;
    remain -= 4;
}