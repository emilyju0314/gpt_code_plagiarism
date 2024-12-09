MemoryHandle::MemoryHandle(size_t size) : size_(size), buf_(nullptr) {
  if (size_ <= 256) {
    // Memory allocation in cuda is always aligned to at least 256 bytes.
    // In many cases it is 512 bytes.
    allocSize_ = 256;
  } else if (size_ <= 512) {
    allocSize_ = 512;
  } else if (size_ <= (1 << 16)) {
    // Allocate multiple of 1024 bytes.
    allocSize_ = (size + 1023) & ~(1023);
  } else {
    allocSize_ = size_;
  }
}