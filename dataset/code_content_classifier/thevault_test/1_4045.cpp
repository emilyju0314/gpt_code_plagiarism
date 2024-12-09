Chunk(int device_id, cnrtQueue_t queue, size_t size, ChunkPool* pool,
        void* ptr)
      : device_id(device_id),
        queue(queue),
        size(size),
        pool(pool),
        ptr(ptr),
        allocated(0),
        prev(nullptr),
        next(nullptr),
        queue_in_use(),
        notifier_count(0) {}