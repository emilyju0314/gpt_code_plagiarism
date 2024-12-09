ts::ByteBlock ts::UString::toDVB(size_type start, size_type count, const DVBCharset* charset) const
{
    if (start >= length()) {
        return ByteBlock();
    }
    else {
        // The maximum number of DVB bytes per character is 4 (worst case in UTF-8).
        ByteBlock bb(UTF8_CHAR_MAX_SIZE * std::min(length() - start, count));

        // Convert the string.
        uint8_t* buffer = bb.data();
        size_type size = bb.size();
        toDVB(buffer, size, start, count, charset);

        // Truncate unused bytes.
        assert(size <= bb.size());
        bb.resize(bb.size() - size);
        return bb;
    }
}