size_t ts::DTVProperties::add(uint32_t cmd, uint32_t data)
{
    assert (_prop_head.num < DTV_IOCTL_MAX_MSGS);
    _prop_buffer[_prop_head.num].cmd = cmd;
    _prop_buffer[_prop_head.num].u.data = data;
    return size_t(_prop_head.num++);
}