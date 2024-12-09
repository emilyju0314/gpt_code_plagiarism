TEST_P(DeprecationTests, BGLEntryMultisampledDeprecated) {
    wgpu::BindGroupLayoutEntry entry{};
    entry.visibility = wgpu::ShaderStage::Fragment;
    entry.type = wgpu::BindingType::SampledTexture;
    entry.multisampled = true;
    entry.binding = 0;

    wgpu::BindGroupLayoutDescriptor desc;
    desc.entryCount = 1;
    desc.entries = &entry;
    EXPECT_DEPRECATION_WARNING(device.CreateBindGroupLayout(&desc));
}