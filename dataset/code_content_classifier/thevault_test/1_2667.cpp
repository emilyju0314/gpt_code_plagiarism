size_t write_to_string(char* ptr, size_t size, size_t count, std::string* stream)
{
    const size_t num = size * count;
    stream->append(ptr, 0, num);
    return num;
}