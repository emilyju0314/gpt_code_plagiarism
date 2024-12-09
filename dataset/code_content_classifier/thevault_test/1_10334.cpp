int WriteBase64Str(
    const void* buffer,
    int bytes,
    char* encoded_buffer,
    int encoded_bytes)
{
    const int written = WriteBase64(
        buffer,
        bytes,
        encoded_buffer,
        encoded_bytes - 1);

    encoded_buffer[written] = '\0';

    return written;
}