TEST_P(IndexFormatTest, SetIndexBufferDifferentFormats) {
    wgpu::RenderPipeline pipeline = MakeTestPipeline(wgpu::IndexFormat::Undefined,
                                                     wgpu::PrimitiveTopology::TriangleList);

    wgpu::Buffer vertexBuffer = utils::CreateBufferFromData<float>(
        device, wgpu::BufferUsage::Vertex,
        {-1.0f, -1.0f, 0.0f, 1.0f, 1.0f, -1.0f, 0.0f, 1.0f, -1.0f, 1.0f, 0.0f, 1.0f});
    wgpu::Buffer indexBuffer32 =
        utils::CreateBufferFromData<uint32_t>(device, wgpu::BufferUsage::Index, {0, 1, 2});
    wgpu::Buffer indexBuffer16 =
        utils::CreateBufferFromData<uint16_t>(device, wgpu::BufferUsage::Index, {0, 1, 2, 0});

    wgpu::CommandEncoder encoder = device.CreateCommandEncoder();
    {
        wgpu::RenderPassEncoder pass = encoder.BeginRenderPass(&renderPass.renderPassInfo);
        pass.SetIndexBufferWithFormat(indexBuffer32, wgpu::IndexFormat::Uint32);
        pass.SetPipeline(pipeline);
        pass.SetVertexBuffer(0, vertexBuffer);
        pass.DrawIndexed(3);
        pass.EndPass();
    }

    wgpu::CommandBuffer commands = encoder.Finish();
    queue.Submit(1, &commands);

    EXPECT_PIXEL_RGBA8_EQ(RGBA8(0, 255, 0, 255), renderPass.color, 100, 300);

    encoder = device.CreateCommandEncoder();
    {
        wgpu::RenderPassEncoder pass = encoder.BeginRenderPass(&renderPass.renderPassInfo);
        pass.SetIndexBufferWithFormat(indexBuffer16, wgpu::IndexFormat::Uint16);
        pass.SetPipeline(pipeline);
        pass.SetVertexBuffer(0, vertexBuffer);
        pass.DrawIndexed(3);
        pass.EndPass();
    }

    commands = encoder.Finish();
    queue.Submit(1, &commands);

    EXPECT_PIXEL_RGBA8_EQ(RGBA8(0, 255, 0, 255), renderPass.color, 100, 300);
}