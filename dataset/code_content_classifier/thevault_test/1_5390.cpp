void ts::AbstractTransportListTable::addSection(BinaryTable& table,
                                                int& section_number,
                                                uint8_t* payload,
                                                uint8_t*& data,
                                                size_t& remain) const
{
    table.addSection(new Section(_table_id,
                                 true,   // is_private_section
                                 _tid_ext,
                                 version,
                                 is_current,
                                 uint8_t(section_number),
                                 uint8_t(section_number),   //last_section_number
                                 payload,
                                 data - payload)); // payload_size,

    // Reinitialize pointers.
    remain += data - payload;
    data = payload;
    section_number++;
}