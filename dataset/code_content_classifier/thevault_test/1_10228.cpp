bool adns_9800::new_motion_data_available()
{
    uint8_t const motion_reg = read_reg(REG_Motion);
    bool const new_data_available = (motion_reg & 0x80) > 0;
    return new_data_available;
}