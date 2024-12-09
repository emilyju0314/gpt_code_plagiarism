size_t ts::DescriptorList::lengthSerialize(uint8_t*& addr, size_t& size, size_t start, uint16_t reserved_bits, size_t length_bits) const
{
    assert(size >= 2);

    // Not more than 16 bits in the length field.
    length_bits = std::min<size_t>(length_bits, 16);

    // Reserve space for descriptor list length
    uint8_t* length_addr = addr;
    addr += 2;
    size -= 2;

    // Insert descriptor list
    size_t result = serialize(addr, size, start);

    // Update length
    size_t length = addr - length_addr - 2;
    PutUInt16(length_addr, uint16_t(length | (reserved_bits << length_bits)));

    return result;
}