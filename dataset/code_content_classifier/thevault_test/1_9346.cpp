bool RingBufferDawn::reset(size_t size) {
  if (size > mSize)
    return false;

  mHead = 0;
  mTail = 0;

  wgpu::BufferDescriptor descriptor;
  descriptor.usage = wgpu::BufferUsage::MapWrite | wgpu::BufferUsage::CopySrc;
  descriptor.size = mSize;
  descriptor.mappedAtCreation = true;
  mBuf = mBufferManager->mContext->createBuffer(descriptor);
  mPixels = mBuf.GetMappedRange();

  return true;
}