TEST_F(IndexBufferValidationTest, IndexBufferFormatMatchesPipelineStripFormat) {
    wgpu::RenderPipeline pipeline32 = MakeTestPipeline(wgpu::IndexFormat::Uint32,
                                                       wgpu::PrimitiveTopology::TriangleStrip);
    wgpu::RenderPipeline pipeline16 = MakeTestPipeline(wgpu::IndexFormat::Uint16,
                                                       wgpu::PrimitiveTopology::LineStrip);

    wgpu::Buffer indexBuffer =
        utils::CreateBufferFromData<uint32_t>(device, wgpu::BufferUsage::Index, {0, 1, 2});

    utils::ComboRenderBundleEncoderDescriptor renderBundleDesc = {};
    renderBundleDesc.colorFormatsCount = 1;
    renderBundleDesc.cColorFormats[0] = wgpu::TextureFormat::RGBA8Unorm;

    // Expected to fail because pipeline and index formats don't match.
    {
        wgpu::RenderBundleEncoder encoder = device.CreateRenderBundleEncoder(&renderBundleDesc);
        encoder.SetIndexBufferWithFormat(indexBuffer, wgpu::IndexFormat::Uint16);
        encoder.SetPipeline(pipeline32);
        encoder.DrawIndexed(3);
        ASSERT_DEVICE_ERROR(encoder.Finish());
    }

    {
        wgpu::RenderBundleEncoder encoder = device.CreateRenderBundleEncoder(&renderBundleDesc);
        encoder.SetIndexBufferWithFormat(indexBuffer, wgpu::IndexFormat::Uint32);
        encoder.SetPipeline(pipeline16);
        encoder.DrawIndexed(3);
        ASSERT_DEVICE_ERROR(encoder.Finish());
    }

    // Expected to succeed because pipeline and index formats match.
    {
        wgpu::RenderBundleEncoder encoder = device.CreateRenderBundleEncoder(&renderBundleDesc);
        encoder.SetIndexBufferWithFormat(indexBuffer, wgpu::IndexFormat::Uint16);
        encoder.SetPipeline(pipeline16);
        encoder.DrawIndexed(3);
        encoder.Finish();
    }

    {
        wgpu::RenderBundleEncoder encoder = device.CreateRenderBundleEncoder(&renderBundleDesc);
        encoder.SetIndexBufferWithFormat(indexBuffer, wgpu::IndexFormat::Uint32);
        encoder.SetPipeline(pipeline32);
        encoder.DrawIndexed(3);
        encoder.Finish();
    }
}