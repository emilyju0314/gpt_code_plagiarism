TEST_P(ViewportTest, EmptyViewport) {
    utils::ComboRenderPipelineDescriptor pipelineDescriptor(device);
    pipelineDescriptor.cColorStates[0].format = wgpu::TextureFormat::RGBA8Unorm;
    pipelineDescriptor.vertexStage.module = mQuadVS;
    pipelineDescriptor.cFragmentStage.module = mQuadFS;
    wgpu::RenderPipeline pipeline = device.CreateRenderPipeline(&pipelineDescriptor);

    utils::BasicRenderPass renderPass = utils::CreateBasicRenderPass(device, 1, 1);

    auto DoEmptyViewportTest = [&](uint32_t width, uint32_t height) {
        wgpu::CommandEncoder encoder = device.CreateCommandEncoder();
        wgpu::RenderPassEncoder pass = encoder.BeginRenderPass(&renderPass.renderPassInfo);
        pass.SetPipeline(pipeline);
        pass.SetViewport(0.0f, 0.0f, width, height, 0.0f, 1.0f);
        pass.Draw(6);
        pass.EndPass();

        wgpu::CommandBuffer commands = encoder.Finish();
        queue.Submit(1, &commands);

        EXPECT_PIXEL_RGBA8_EQ(RGBA8::kZero, renderPass.color, 0, 0);
    };

    // Test with a 0x0, 0xN and nx0 viewport.
    DoEmptyViewportTest(0, 0);
    DoEmptyViewportTest(0, 1);
    DoEmptyViewportTest(1, 0);
}