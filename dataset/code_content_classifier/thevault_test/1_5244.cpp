bool ts::UNT::DeserializeDevices(Devices& devs, const uint8_t*& data, size_t& remain)
{
    // Get compatibility descriptor.
    if (!DeserializeCompatibilityDescriptorList(devs.compatibilityDescriptor, data, remain) || remain < 2) {
        return false;
    }

    // Get platform loop length.
    const uint8_t* const data_end = data + 2 + GetUInt16(data);
    data += 2;
    remain -= 2;

    // Get platform descriptions.
    while (data < data_end) {
        Platform& platform(devs.platforms.newEntry());
        if (!DeserializeDescriptorList(platform.target_descs, data, remain) || !DeserializeDescriptorList(platform.operational_descs, data, remain)) {
            return false;
        }
    }
    return true;
}