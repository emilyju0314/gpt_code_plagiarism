ts::UString::size_type ts::UString::toDVBWithByteLength(uint8_t*& buffer, size_t& size, size_type start, size_type count, const DVBCharset* charset) const
{
    // Skip degenerated cases where there is nothing to do.
    if (buffer == nullptr || size == 0 || start >= length()) {
        return 0;
    }

    // Write the DVB string at second byte, keep the first one for the length.
    uint8_t* dvbBuffer = buffer + 1;

    // We cannot write more that 255 bytes because the length must fit in one byte.
    const size_type dvbMaxSize = std::min<size_t>(size - 1, 0xFF);
    size_type dvbSize = dvbMaxSize;

    // Convert the string.
    const size_type result = toDVB(dvbBuffer, dvbSize, start, count, charset);

    // Compute the actual DVB size.
    assert(dvbSize <= dvbMaxSize);
    dvbSize = dvbMaxSize - dvbSize;

    // Update size at the beginning of the string.
    assert(dvbSize <= 0xFF);
    buffer[0] = uint8_t(dvbSize);

    // Update user's buffer characteristics.
    assert(size >= dvbSize + 1);
    buffer += dvbSize + 1;
    size -= dvbSize + 1;

    return result;
}