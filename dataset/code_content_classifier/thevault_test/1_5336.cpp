ts::ByteBlock ts::UString::toDVBWithByteLength(size_type start, size_type count, const DVBCharset* charset) const
{
    if (start >= length()) {
        // Empty string, return one byte containing 0 (the length).
        return ByteBlock(1, 0);
    }
    else {
        // The maximum number of DVB bytes is 255 so that the size fits in one byte.
        ByteBlock bb(256);

        // Convert the string.
        uint8_t* buffer = bb.data() + 1;
        size_type size = bb.size() - 1;
        toDVB(buffer, size, start, count, charset);

        // Truncate unused bytes.
        assert(size < bb.size());
        bb.resize(bb.size() - size);

        // Update length byte.
        bb[0] = uint8_t(bb.size() - 1);
        return bb;
    }
}