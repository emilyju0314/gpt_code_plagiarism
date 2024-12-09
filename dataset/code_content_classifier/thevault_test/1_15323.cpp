vector(iterator __begin, iterator __end) noexcept {
        size_type __length = __end - __begin;
        __map_begin = __alloc_and_copy(__begin, __end);
        __map_end = __storage_end = __map_begin + __length;
    }