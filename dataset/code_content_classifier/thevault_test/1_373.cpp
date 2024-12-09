TEST_F(WireCreateReadyPipelineTest, CreateReadyRenderPipelineError) {
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
                apiDevice, WGPUCreateReadyPipelineStatus_Error, nullptr, "Some error message");
        }));

    FlushClient();

    EXPECT_CALL(*mockCreateReadyRenderPipelineCallback,
                Call(WGPUCreateReadyPipelineStatus_Error, _, StrEq("Some error message"), this))
        .Times(1);

    FlushServer();
}