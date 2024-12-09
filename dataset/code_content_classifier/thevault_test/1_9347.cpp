RingBufferDawn *BufferManagerDawn::allocate(size_t size, size_t *offset) {
  // If update data by sync method, create new buffer to upload every frame.
  // If updaye data by async method, get new buffer from pool if available. If
  // no available buffer and size is enough in the buffer pool, create a new
  // buffer. If size reach the limit of the buffer pool, force wait for the
  // buffer on mapping. Get the last one and check if the ring buffer is full.
  // If the buffer can hold extra size space, use the last one directly.
  // TODO(yizhou): Return nullptr if size reach the limit or no available
  // buffer, this means small bubbles in some of the ring buffers and we haven't
  // deal with the problem now.

  RingBufferDawn *ringBuffer = nullptr;
  size_t cur_offset = 0;
  if (mSync) {
    // Upper limit
    if (mUsedSize + size > mBufferPoolSize) {
      return nullptr;
    }

    ringBuffer = new RingBufferDawn(this, size);
    mEnqueuedBufferList.emplace_back(ringBuffer);
  } else  // Buffer mapping async
  {
    while (!mMappedBufferList.empty()) {
      ringBuffer = static_cast<RingBufferDawn *>(mMappedBufferList.front());
      if (ringBuffer->getAvailableSize() < size) {
        mMappedBufferList.pop();
        ringBuffer = nullptr;
      } else {
        break;
      }
    }

    if (ringBuffer == nullptr) {
      if (mCount < BUFFER_MAX_COUNT) {
        mUsedSize += size;
        ringBuffer = new RingBufferDawn(this, BUFFER_PER_ALLOCATE_SIZE);
        mMappedBufferList.push(ringBuffer);
        mCount++;
      } else if (mMappedBufferList.size() + mEnqueuedBufferList.size() <
                 mCount) {
        // Force wait for the buffer remapping
        while (mMappedBufferList.empty()) {
          mContext->WaitABit();
        }

        ringBuffer = static_cast<RingBufferDawn *>(mMappedBufferList.front());
        if (ringBuffer->getAvailableSize() < size) {
          mMappedBufferList.pop();
          ringBuffer = nullptr;
        }
      } else  // Upper limit
      {
        return nullptr;
      }
    }

    if (mEnqueuedBufferList.empty() ||
        mEnqueuedBufferList.back() != ringBuffer) {
      mEnqueuedBufferList.emplace_back(ringBuffer);
    }

    // allocate size in the ring buffer
    cur_offset = ringBuffer->allocate(size);
    *offset = cur_offset;
  }

  return ringBuffer;
}