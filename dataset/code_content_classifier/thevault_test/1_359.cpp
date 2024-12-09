RenderPassEncoder::RenderPassEncoder(DeviceBase* device,
                                         CommandEncoder* commandEncoder,
                                         EncodingContext* encodingContext,
                                         PassResourceUsageTracker usageTracker,
                                         uint32_t renderTargetWidth,
                                         uint32_t renderTargetHeight)
        : RenderEncoderBase(device, encodingContext),
          mCommandEncoder(commandEncoder),
          mRenderTargetWidth(renderTargetWidth),
          mRenderTargetHeight(renderTargetHeight) {
        mUsageTracker = std::move(usageTracker);
    }