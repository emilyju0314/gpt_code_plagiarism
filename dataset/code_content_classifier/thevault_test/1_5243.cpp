bool ts::UNT::DeserializeCompatibilityDescriptorList(CompatibilityDescriptorList& dlist, const uint8_t*& data, size_t& remain)
{
    // Get descriptor loop length and count.
    if (remain < 4) {
        return false;
    }
    const size_t compatibilityDescriptorLength = GetUInt16(data);
    size_t descriptorCount = GetUInt16(data + 2);
    const uint8_t* const data_end = data + 2 + compatibilityDescriptorLength;

    // Check structure size.
    if (remain < 2 + compatibilityDescriptorLength) {
        return false;
    }
    data += 4;
    remain -= 4;

    // Get outer descriptor loop.
    while (descriptorCount > 0) {

        // Deserialize fixed part.
        if (remain < 11) {
            return false;
        }
        CompatibilityDescriptor cdesc;
        cdesc.descriptorType = data[0];
        const size_t descriptorLength = data[1];
        cdesc.specifierType = data[2];
        cdesc.specifierData = GetUInt24(data + 3);
        cdesc.model = GetUInt16(data + 6);
        cdesc.version = GetUInt16(data + 8);
        const size_t subDescriptorCount = data[10];
        if (remain < 2 + descriptorLength) {
            return false;
        }

        // Deserialize sub-descriptors.
        assert(descriptorLength >= 9);
        cdesc.subDescriptors.add(data + 11, descriptorLength - 9);
        data += 2 + descriptorLength;
        remain -= 2 + descriptorLength;

        // Check that the expected number of descriptors were read.
        if (cdesc.subDescriptors.size() != subDescriptorCount) {
            return false;
        }

        // Next compatibilityDescriptor() entry.
        dlist.push_back(cdesc);
        descriptorCount--;
    }

    // Check that we reached the expected end of structure.
    return data == data_end && descriptorCount == 0;
}