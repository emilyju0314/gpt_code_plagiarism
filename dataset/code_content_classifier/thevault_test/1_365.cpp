TEST_P(DeprecationTests, TextureComponentTypeFloatWhenDepthComparisonIsExpected) {
    wgpu::ShaderModule module =
        utils::CreateShaderModule(device, utils::SingleShaderStage::Compute, R"(
            #version 450
            layout(set = 0, binding = 0) uniform samplerShadow samp;
            layout(set = 0, binding = 1) uniform texture2D tex;

            void main() {
                texture(sampler2DShadow(tex, samp), vec3(0.5, 0.5, 0.5));
            }
        )");

    {
        wgpu::BindGroupLayout goodBgl = utils::MakeBindGroupLayout(
            device,
            {{0, wgpu::ShaderStage::Compute, wgpu::BindingType::ComparisonSampler},
             {1, wgpu::ShaderStage::Compute, wgpu::BindingType::SampledTexture, false, 0, false,
              wgpu::TextureViewDimension::e2D, wgpu::TextureComponentType::DepthComparison}});

        wgpu::ComputePipelineDescriptor goodDesc;
        goodDesc.layout = utils::MakeBasicPipelineLayout(device, &goodBgl);
        goodDesc.computeStage.module = module;
        goodDesc.computeStage.entryPoint = "main";

        device.CreateComputePipeline(&goodDesc);
    }

    {
        wgpu::BindGroupLayout badBgl = utils::MakeBindGroupLayout(
            device, {{0, wgpu::ShaderStage::Compute, wgpu::BindingType::ComparisonSampler},
                     {1, wgpu::ShaderStage::Compute, wgpu::BindingType::SampledTexture, false, 0,
                      false, wgpu::TextureViewDimension::e2D, wgpu::TextureComponentType::Float}});

        wgpu::ComputePipelineDescriptor badDesc;
        badDesc.layout = utils::MakeBasicPipelineLayout(device, &badBgl);
        badDesc.computeStage.module = module;
        badDesc.computeStage.entryPoint = "main";

        EXPECT_DEPRECATION_WARNING(device.CreateComputePipeline(&badDesc));
    }
}