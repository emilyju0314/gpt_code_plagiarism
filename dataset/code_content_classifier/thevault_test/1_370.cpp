TEST_F(WireCreateReadyPipelineTest, CreateReadyComputePipelineSuccess) {
    WGPUShaderModuleDescriptor csDescriptor{};
    WGPUShaderModule csModule = wgpuDeviceCreateShaderModule(device, &csDescriptor);
    WGPUShaderModule apiCsModule = api.GetNewShaderModule();
    EXPECT_CALL(api, DeviceCreateShaderModule(apiDevice, _)).WillOnce(Return(apiCsModule));

    WGPUComputePipelineDescriptor descriptor{};
    descriptor.computeStage.module = csModule;
    descriptor.computeStage.entryPoint = "main";

    wgpuDeviceCreateReadyComputePipeline(device, &descriptor,
                                         ToMockCreateReadyComputePipelineCallback, this);

    EXPECT_CALL(api, OnDeviceCreateReadyComputePipelineCallback(apiDevice, _, _, _))
        .WillOnce(InvokeWithoutArgs([&]() {
            api.CallDeviceCreateReadyComputePipelineCallback(
                apiDevice, WGPUCreateReadyPipelineStatus_Success, nullptr, "");
        }));

    FlushClient();

    EXPECT_CALL(*mockCreateReadyComputePipelineCallback,
                Call(WGPUCreateReadyPipelineStatus_Success, _, StrEq(""), this))
        .Times(1);

    FlushServer();
}