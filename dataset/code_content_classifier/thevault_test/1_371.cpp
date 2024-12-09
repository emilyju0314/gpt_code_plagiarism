TEST_F(WireCreateReadyPipelineTest, CreateReadyComputePipelineError) {
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
                apiDevice, WGPUCreateReadyPipelineStatus_Error, nullptr, "Some error message");
        }));

    FlushClient();

    EXPECT_CALL(*mockCreateReadyComputePipelineCallback,
                Call(WGPUCreateReadyPipelineStatus_Error, _, StrEq("Some error message"), this))
        .Times(1);

    FlushServer();
}