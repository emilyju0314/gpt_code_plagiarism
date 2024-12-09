void ts::UNT::addSection(BinaryTable& table,
                         int& section_number,
                         uint8_t* payload,
                         uint8_t*& data,
                         size_t& remain) const
{
    // The table id extension is made of action_type and OUI hash.
    const uint16_t tidext =
        uint16_t(uint16_t(action_type) << 8) |
        uint16_t(((OUI >> 16) & 0xFF) ^ ((OUI >> 8) & 0xFF) ^ (OUI & 0xFF));

    table.addSection(new Section(_table_id,
                                 true,    // is_private_section
                                 tidext,
                                 version,
                                 is_current,
                                 uint8_t(section_number),
                                 uint8_t(section_number),   //last_section_number
                                 payload,
                                 data - payload)); // payload_size,

    // Reinitialize pointers.
    // Restart after constant part of payload (4 bytes).
    remain += data - payload - 4;
    data = payload + 4;
    section_number++;
}