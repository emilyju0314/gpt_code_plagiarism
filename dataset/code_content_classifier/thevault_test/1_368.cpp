TEST_F(IndexBufferValidationTest, IndexBufferOffsetOOBValidation) {
    wgpu::BufferDescriptor bufferDesc;
    bufferDesc.usage = wgpu::BufferUsage::Index;
    bufferDesc.size = 256;
    wgpu::Buffer buffer = device.CreateBuffer(&bufferDesc);

    DummyRenderPass renderPass(device);
    // Control case, using the full buffer, with or without an explicit size is valid.
    {
        wgpu::CommandEncoder encoder = device.CreateCommandEncoder();
        wgpu::RenderPassEncoder pass = encoder.BeginRenderPass(&renderPass);
        // Explicit size
        pass.SetIndexBufferWithFormat(buffer, wgpu::IndexFormat::Uint32, 0, 256);
        // Implicit size
        pass.SetIndexBufferWithFormat(buffer, wgpu::IndexFormat::Uint32, 0, 0);
        pass.SetIndexBufferWithFormat(buffer, wgpu::IndexFormat::Uint32, 256 - 4, 0);
        pass.SetIndexBufferWithFormat(buffer, wgpu::IndexFormat::Uint32, 4, 0);
        // Implicit size of zero
        pass.SetIndexBufferWithFormat(buffer, wgpu::IndexFormat::Uint32, 256, 0);
        pass.EndPass();
        encoder.Finish();
    }

    // Bad case, offset + size is larger than the buffer
    {
        wgpu::CommandEncoder encoder = device.CreateCommandEncoder();
        wgpu::RenderPassEncoder pass = encoder.BeginRenderPass(&renderPass);
        pass.SetIndexBufferWithFormat(buffer, wgpu::IndexFormat::Uint32, 4, 256);
        pass.EndPass();
        ASSERT_DEVICE_ERROR(encoder.Finish());
    }

    // Bad case, size is 0 but the offset is larger than the buffer
    {
        wgpu::CommandEncoder encoder = device.CreateCommandEncoder();
        wgpu::RenderPassEncoder pass = encoder.BeginRenderPass(&renderPass);
        pass.SetIndexBufferWithFormat(buffer, wgpu::IndexFormat::Uint32, 256 + 4, 0);
        pass.EndPass();
        ASSERT_DEVICE_ERROR(encoder.Finish());
    }

    utils::ComboRenderBundleEncoderDescriptor renderBundleDesc = {};
    renderBundleDesc.colorFormatsCount = 1;
    renderBundleDesc.cColorFormats[0] = wgpu::TextureFormat::RGBA8Unorm;

    // Control case, using the full buffer, with or without an explicit size is valid.
    {
        wgpu::RenderBundleEncoder encoder = device.CreateRenderBundleEncoder(&renderBundleDesc);
        // Explicit size
        encoder.SetIndexBufferWithFormat(buffer, wgpu::IndexFormat::Uint32, 0, 256);
        // Implicit size
        encoder.SetIndexBufferWithFormat(buffer, wgpu::IndexFormat::Uint32, 0, 0);
        encoder.SetIndexBufferWithFormat(buffer, wgpu::IndexFormat::Uint32, 256 - 4, 0);
        encoder.SetIndexBufferWithFormat(buffer, wgpu::IndexFormat::Uint32, 4, 0);
        // Implicit size of zero
        encoder.SetIndexBufferWithFormat(buffer, wgpu::IndexFormat::Uint32, 256, 0);
        encoder.Finish();
    }

    // Bad case, offset + size is larger than the buffer
    {
        wgpu::RenderBundleEncoder encoder = device.CreateRenderBundleEncoder(&renderBundleDesc);
        encoder.SetIndexBufferWithFormat(buffer, wgpu::IndexFormat::Uint32, 4, 256);
        ASSERT_DEVICE_ERROR(encoder.Finish());
    }

    // Bad case, size is 0 but the offset is larger than the buffer
    {
        wgpu::RenderBundleEncoder encoder = device.CreateRenderBundleEncoder(&renderBundleDesc);
        encoder.SetIndexBufferWithFormat(buffer, wgpu::IndexFormat::Uint32, 256 + 4, 0);
        ASSERT_DEVICE_ERROR(encoder.Finish());
    }
}