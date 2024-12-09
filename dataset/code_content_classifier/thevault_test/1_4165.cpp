bool SendData(void *&buffer, size_t size, const uint8_t *data)
{
    if (size <= 0) {
        return false;
    }
    buffer = malloc(size);
    if (buffer == nullptr) {
        return false;
    }
    if (memcpy_s(buffer, size, data, size) != EOK) {
        return false;
    }
    return true;
}