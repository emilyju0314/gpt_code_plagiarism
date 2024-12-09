buffer_base(std::shared_ptr<AllocatorT> allocator, cudaStream_t stream, size_type n = 0)
    : data_(nullptr), size_(n), capacity_(n), stream_(stream), allocator_(std::move(allocator))
  {
    if (capacity_ > 0) {
      data_ =
        static_cast<value_type*>(allocator_->allocate(capacity_ * sizeof(value_type), stream_));
      RAFT_CUDA_TRY(cudaStreamSynchronize(stream_));
    }
  }