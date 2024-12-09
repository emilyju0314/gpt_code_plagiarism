void ts::ATSCEIT::addSection(BinaryTable& table, int& section_number, size_t& event_count, uint8_t* payload, uint8_t*& data, size_t& remain) const
{
    // Update fixed part and event count in this section.
    payload[0] = protocol_version;
    payload[1] = uint8_t(event_count);

    // Add a new section in the table.
    table.addSection(new Section(_table_id,
                                 true,         // is_private_section
                                 source_id,    // tid_ext
                                 version,
                                 is_current,
                                 uint8_t(section_number),
                                 uint8_t(section_number), // last_section_number
                                 payload,
                                 data - payload)); // payload_size,

    // Reinitialize payload pointers after fixed part (start of the first event).
    remain += data - payload - 2;
    data = payload + 2;

    // Reset event count in payload, move to next section.
    event_count = 0;
    section_number++;
}