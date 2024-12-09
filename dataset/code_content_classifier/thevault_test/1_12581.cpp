explicit FixedWorkStealingQueue(const size_t capacity)
        : top_(0), bottom_(0), capacity_(capacity)
    {
        jobs_.resize(capacity);
    }