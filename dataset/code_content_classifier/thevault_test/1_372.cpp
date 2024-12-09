TEST_F(WireCreateReadyPipelineTest, CreateReadyRenderPipelineSuccess) {
    WGPUShaderModuleDescriptor vertexDescriptor = {};
    WGPUShaderModule vsModule = wgpuDeviceCreateShaderModule(device, &vertexDescriptor);
    WGPUShaderModule apiVsModule = api.GetNewShaderModule();
    EXPECT_CALL(api, DeviceCreateShaderModule(apiDevice, _)).WillOnce(Return(apiVsModule));

    WGPURenderPipelineDescriptor pipelineDescriptor{};
    pipelineDescriptor.vertexStage.module = vsModule;
    pipelineDescriptor.vertexStage.entryPoint = "main";

    WGPUProgrammableStageDescriptor fragmentStage = {};
    fragmentStage.module = vsModule;
    fragmentStage.entryPoint = "main";
    pipelineDescriptor.fragmentStage = &fragmentStage;

    wgpuDeviceCreateReadyRenderPipeline(device, &pipelineDescriptor,
                                        ToMockCreateReadyRenderPipelineCallback, this);
    EXPECT_CALL(api, OnDeviceCreateReadyRenderPipelineCallback(apiDevice, _, _, _))
        .WillOnce(InvokeWithoutArgs([&]() {
            api.CallDeviceCreateReadyRenderPipelineCallback(
                apiDevice, WGPUCreateReadyPipelineStatus_Success, nullptr, "");
        }));

    FlushClient();

    EXPECT_CALL(*mockCreateReadyRenderPipelineCallback,
                Call(WGPUCreateReadyPipelineStatus_Success, _, StrEq(""), this))
        .Times(1);

    FlushServer();
}