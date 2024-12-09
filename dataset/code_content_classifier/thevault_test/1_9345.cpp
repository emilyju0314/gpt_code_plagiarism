BufferDawn::BufferDawn(ContextDawn *context,
                       int totalCmoponents,
                       int numComponents,
                       std::vector<float> *buffer,
                       bool isIndex)
    : mUsage(isIndex ? wgpu::BufferUsage::Index : wgpu::BufferUsage::Vertex),
      mTotoalComponents(totalCmoponents),
      mStride(0),
      mOffset(nullptr) {
  mSize = numComponents * sizeof(float);

  // Create buffer for vertex buffer. Because float is multiple of 4 bytes,
  // dummy padding isnt' needed.
  int bufferSize = sizeof(float) * static_cast<int>(buffer->size());
  wgpu::BufferDescriptor descriptor;
  descriptor.usage = mUsage | wgpu::BufferUsage::CopyDst;
  descriptor.size = bufferSize;
  descriptor.mappedAtCreation = false;
  mBuf = context->createBuffer(descriptor);

  context->setBufferData(mBuf, bufferSize, buffer->data(), bufferSize);
}