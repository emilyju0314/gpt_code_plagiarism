TEST_P(SetIndexBufferDeprecationTests, Uint16) {
    wgpu::RenderPipeline pipeline = MakeTestPipeline(wgpu::IndexFormat::Uint16);

    wgpu::Buffer vertexBuffer = utils::CreateBufferFromData<float>(
        device, wgpu::BufferUsage::Vertex,
        {-1.0f, -1.0f, 0.0f, 1.0f, 1.0f, -1.0f, 0.0f, 1.0f, -1.0f, 1.0f, 0.0f, 1.0f});
    // If this is interpreted as uint32, it will have index 1 and 2 be both 0 and render nothing
    wgpu::Buffer indexBuffer =
        utils::CreateBufferFromData<uint16_t>(device, wgpu::BufferUsage::Index, {1, 2, 0, 0, 0, 0});

    wgpu::CommandEncoder encoder = device.CreateCommandEncoder();
    {
        wgpu::RenderPassEncoder pass = encoder.BeginRenderPass(&renderPass.renderPassInfo);
        pass.SetPipeline(pipeline);
        pass.SetVertexBuffer(0, vertexBuffer);
        EXPECT_DEPRECATION_WARNING(pass.SetIndexBuffer(indexBuffer));
        pass.DrawIndexed(3);
        pass.EndPass();
    }

    wgpu::CommandBuffer commands = encoder.Finish();
    queue.Submit(1, &commands);

    EXPECT_PIXEL_RGBA8_EQ(RGBA8::kGreen, renderPass.color, 100, 300);
}