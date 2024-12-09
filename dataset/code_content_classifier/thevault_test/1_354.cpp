TEST_P(IndexFormatTest, Uint32PrimitiveRestart) {
    wgpu::RenderPipeline pipeline = MakeTestPipeline(wgpu::IndexFormat::Uint32);

    wgpu::Buffer vertexBuffer = utils::CreateBufferFromData<float>(
        device, wgpu::BufferUsage::Vertex,
        {
            0.0f, -1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f,  1.0f, 0.0f, 0.0f,
            0.0f, 1.0f,  0.0f, 1.0f, 0.0f, 1.0f, -1.0f, 1.0f, 0.0f, 1.0f,
        });
    wgpu::Buffer indexBuffer =
        utils::CreateBufferFromData<uint32_t>(device, wgpu::BufferUsage::Index,
                                              {
                                                  0,
                                                  1,
                                                  2,
                                                  0xFFFFFFFFu,
                                                  3,
                                                  4,
                                                  2,
                                              });

    wgpu::CommandEncoder encoder = device.CreateCommandEncoder();
    {
        wgpu::RenderPassEncoder pass = encoder.BeginRenderPass(&renderPass.renderPassInfo);
        pass.SetPipeline(pipeline);
        pass.SetVertexBuffer(0, vertexBuffer);
        pass.SetIndexBufferWithFormat(indexBuffer, wgpu::IndexFormat::Uint32);
        pass.DrawIndexed(7);
        pass.EndPass();
    }

    wgpu::CommandBuffer commands = encoder.Finish();
    queue.Submit(1, &commands);

    EXPECT_PIXEL_RGBA8_EQ(RGBA8::kGreen, renderPass.color, 190, 190);  // A
    EXPECT_PIXEL_RGBA8_EQ(RGBA8::kGreen, renderPass.color, 210, 210);  // B
    EXPECT_PIXEL_RGBA8_EQ(RGBA8::kZero, renderPass.color, 210, 190);   // C
}