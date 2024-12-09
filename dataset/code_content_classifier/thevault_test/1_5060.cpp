size_t ts::DescriptorList::serialize(ByteBlock& bb, size_t start) const
{
    // Keep track of byte block size before serializing the descriptor list.
    const size_t previous_size = bb.size();

    // Increase the byte block size by the max size of a descriptor list.
    size_t added_size = 0xFFFF;
    bb.resize(previous_size + added_size);

    // Serialize the descriptor list into the extended area.
    uint8_t* data = bb.data() + previous_size;
    size_t size = added_size;
    serialize(data, size, start);

    // 'size' contains the remaining size, from 'added_size'.
    // Update 'added_size' to contain the size of the serialized descriptor list.
    assert(size <= added_size);
    added_size -= size;

    // Shrink the byte block to the end of descriptor list.
    bb.resize(previous_size + added_size);
    return added_size;
}