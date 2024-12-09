bool ts::UNT::serializeDevices(const Devices& devs, uint8_t*& data, size_t& remain) const
{
    // Check if the structure is truncated (not enough space).
    bool truncated = false;

    // Minimum required size: 6 byte (4 for an empty compatibilityDescriptor() and 2 for platform_loop_length).
    constexpr size_t min_size = 6;
    if (remain < min_size) {
        return false;
    }

    // Keep room for 2 additional bytes for platform_loop_length.
    remain -= 2;

    // Serialize the compatibilityDescriptor().
    // Remember starting point to update compatibilityDescriptorLength and descriptorCount.
    // Skip them, they will be updated later.
    uint8_t* comp_desc_base = data;
    uint16_t descriptorCount = 0;
    data += 4;
    remain -= 4;

    // Serialize all entries in the compatibilityDescriptor().
    for (auto it = devs.compatibilityDescriptor.begin(); !truncated && it != devs.compatibilityDescriptor.end(); ++it) {
        // Check that we have space for the fixed part.
        if (remain < 11) {
            truncated = true;
            break;
        }
        // Fill fixed part. Skip descriptorLength and subDescriptorCount for now.
        uint8_t* desc_base = data;
        PutUInt8(data, it->descriptorType);
        PutUInt8(data + 2, it->specifierType);
        PutUInt24(data + 3, it->specifierData);
        PutUInt16(data + 6, it->model);
        PutUInt16(data + 8, it->version);
        data += 11;
        remain -= 11;
        // Serialize subDescriptor().
        const size_t count = it->subDescriptors.serialize(data, remain);
        // Update descriptorLength and subDescriptorCount.
        PutUInt8(desc_base + 1, uint8_t(data - desc_base - 2));
        PutUInt8(desc_base + 10, uint8_t(count));
        // Check if all sub-descriptors have been serialized.
        if (count < it->subDescriptors.count()) {
            truncated = true;
        }
        descriptorCount++;
    }

    // Update compatibilityDescriptorLength and descriptorCount.
    PutUInt16(comp_desc_base, uint16_t(data - comp_desc_base - 2));
    PutUInt16(comp_desc_base + 2, descriptorCount);

    // End of compatibilityDescriptor().
    // Restore additional bytes for platform_loop_length.
    remain += 2;

    // Save address of platform_loop_length and skip it.
    uint8_t* const platform_base = data;
    data += 2;
    remain -= 2;

    // Serialize all platform descriptions.
    for (auto it = devs.platforms.begin(); !truncated && it != devs.platforms.end(); ++it) {
        // Check that we have space for the fixed parts.
        if (remain < 4) {
            truncated = true;
            break;
        }
        // Serialize target descriptor loop, then operational descriptor loop.
        remain -= 2;
        const size_t tg_count = it->second.target_descs.lengthSerialize(data, remain);
        remain += 2;
        const size_t op_count = it->second.operational_descs.lengthSerialize(data, remain);
        // Check if we could serialize them all.
        truncated = tg_count < it->second.target_descs.count() || op_count < it->second.operational_descs.count();
    }

    // Update platform_loop_length.
    PutUInt16(platform_base, uint8_t(data - platform_base - 2));

    return !truncated;
}