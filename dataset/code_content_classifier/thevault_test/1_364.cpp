TEST_P(DeprecationTests, BGLEntryMultisampledBooleanTracking) {
    // Create a BGL with the deprecated multisampled boolean
    wgpu::BindGroupLayoutEntry entry{};
    entry.visibility = wgpu::ShaderStage::Fragment;
    entry.type = wgpu::BindingType::SampledTexture;
    entry.multisampled = true;
    entry.binding = 0;

    wgpu::BindGroupLayoutDescriptor desc;
    desc.entryCount = 1;
    desc.entries = &entry;
    wgpu::BindGroupLayout bgl;
    EXPECT_DEPRECATION_WARNING(bgl = device.CreateBindGroupLayout(&desc));

    // Create both a multisampled and non-multisampled texture.
    wgpu::TextureDescriptor textureDesc;
    textureDesc.format = wgpu::TextureFormat::RGBA8Unorm;
    textureDesc.usage = wgpu::TextureUsage::Sampled;
    textureDesc.size = {1, 1, 1};
    textureDesc.dimension = wgpu::TextureDimension::e2D;
    textureDesc.sampleCount = 1;
    wgpu::Texture texture1Sample = device.CreateTexture(&textureDesc);

    textureDesc.sampleCount = 4;
    wgpu::Texture texture4Sample = device.CreateTexture(&textureDesc);

    // Creating a bindgroup with that layout is only valid with multisampled = true
    ASSERT_DEVICE_ERROR(utils::MakeBindGroup(device, bgl, {{0, texture1Sample.CreateView()}}));
    utils::MakeBindGroup(device, bgl, {{0, texture4Sample.CreateView()}});
}