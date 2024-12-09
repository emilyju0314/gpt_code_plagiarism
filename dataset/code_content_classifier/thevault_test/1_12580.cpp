FixedPoolAllocator(const size_t block_size, const uint32_t max_blocks)
    {
        assert(block_size >= sizeof(void*));

        block_size_ = block_size;
        max_blocks_ = max_blocks;
        memory_ = new uint8_t[block_size_ * max_blocks_];

        reset();
    }