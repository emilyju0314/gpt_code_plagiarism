ts::UString ts::UString::FromDVBWithByteLength(const uint8_t*& buffer, size_t& size, const DVBCharset* charset)
{
    // Null or empty buffer is a valid empty string.
    if (buffer == nullptr || size == 0) {
        return UString();
    }

    // Address and size of the DVB string.
    const uint8_t* const dvb = buffer + 1;
    const size_type dvbSize = std::min<size_t>(buffer[0], size - 1);

    // Update the user buffer to point after the DVB string.
    buffer += dvbSize + 1;
    size -= dvbSize + 1;

    // Decode the DVB string.
    return FromDVB(dvb, dvbSize, charset);
}