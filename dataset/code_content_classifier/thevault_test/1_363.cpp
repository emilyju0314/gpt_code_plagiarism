TEST_P(DeprecationTests, BGLEntryMultisampledBooleanAndTypeIsAnError) {
    wgpu::BindGroupLayoutEntry entry{};
    entry.visibility = wgpu::ShaderStage::Fragment;
    entry.type = wgpu::BindingType::MultisampledTexture;
    entry.multisampled = true;
    entry.binding = 0;

    wgpu::BindGroupLayoutDescriptor desc;
    desc.entryCount = 1;
    desc.entries = &entry;
    ASSERT_DEVICE_ERROR(device.CreateBindGroupLayout(&desc));
}