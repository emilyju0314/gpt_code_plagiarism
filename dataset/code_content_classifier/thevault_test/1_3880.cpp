explicit CircularBuffer(size_t size, T item)
        : buffer(size), read_index(0), write_index(0), max_size(size), full(false)
    {
        this->put(item);
    }