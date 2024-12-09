size_t ts::DTVProperties::search(uint32_t cmd) const
{
    size_t i;
    for (i = 0; i < size_t(_prop_head.num) && _prop_buffer[i].cmd != cmd; i++) {
    }
    return i;
}