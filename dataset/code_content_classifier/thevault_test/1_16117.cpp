static void saveFrameData(reshade::api::effect_runtime* runtime, grabber_context& grabber_state) {
    device* const device = runtime->get_device();
    command_queue* const queue = runtime->get_command_queue();

    void* state_tracking_context_ptr = nullptr;
    if (!device->get_user_data(state_tracking_context::GUID, &state_tracking_context_ptr)) {
        Logfile::get()->writeError("Error: Built-in depth add-on not loaded!");
        return;
    }
    state_tracking_context &device_state = device->get_user_data<state_tracking_context>(state_tracking_context::GUID);

    if (device_state.selected_depth_stencil == 0) {
        Logfile::get()->writeError("Error: device_state.selected_depth_stencil");
        grabber_state.record = false;
        return;
    }

    TimeMeasurement updateStagingTime("update staging");
    const resource depth_stencil_resource = device_state.selected_depth_stencil;
    const resource_desc depth_stencil_desc = device->get_resource_desc(device_state.selected_depth_stencil);
    if (depth_stencil_desc.texture.format != grabber_state.lastDepthStencilDesc.texture.format
            || depth_stencil_desc.texture.width != grabber_state.lastDepthStencilDesc.texture.width
            || depth_stencil_desc.texture.height != grabber_state.lastDepthStencilDesc.texture.height) {
        grabber_state.updateStagingTexture(device, depth_stencil_desc);
    }
    updateStagingTime.stop();

    // Create a staging texture for copying the depth-stencil data to the CPU.
    TimeMeasurement copyStagingTimeGpu("copy staging (GPU)");
    if (grabber_state.stagingTexture != 0)
    {
        if ((depth_stencil_desc.usage & resource_usage::copy_source) == resource_usage::undefined) {
            Logfile::get()->fatalError("Error: Depth-stencil texture does not allow resource_usage::copy_source.");
        }

        command_list* const cmd_list = queue->get_immediate_command_list();

        cmd_list->barrier(
                grabber_state.stagingTexture,
                resource_usage::cpu_access,
                resource_usage::copy_dest);
        cmd_list->barrier(
                depth_stencil_resource,
                resource_usage::depth_stencil | resource_usage::shader_resource,
                resource_usage::copy_source);

        cmd_list->copy_resource(depth_stencil_resource, grabber_state.stagingTexture);

        cmd_list->barrier(
                depth_stencil_resource,
                resource_usage::copy_source,
                resource_usage::depth_stencil | resource_usage::shader_resource);
        cmd_list->barrier(
                grabber_state.stagingTexture,
                resource_usage::copy_dest,
                resource_usage::cpu_access);
    }
    copyStagingTimeGpu.stop();

    TimeMeasurement copyStagingTimeCpu("copy staging (CPU)");
    float* depthData = copyDepthDataToCpu(
            device, grabber_state.stagingTexture, grabber_state.stagingTextureDesc, depth_stencil_desc);
    copyStagingTimeCpu.stop();

    TimeMeasurement linearizeDepthTime("linearize depth");
    uint16_t* u16Data = new uint16_t[depth_stencil_desc.texture.width * depth_stencil_desc.texture.height];
    linearizeDepthBuffer(depth_stencil_desc.texture.width, depth_stencil_desc.texture.height, depthData, u16Data);
    linearizeDepthTime.stop();

    TimeMeasurement computeNormalMapTime("compute normal map");
    uint8_t* normalDataUint = new uint8_t[depth_stencil_desc.texture.width * depth_stencil_desc.texture.height * 3];
    computeNormalMap(depth_stencil_desc.texture.width, depth_stencil_desc.texture.height, depthData, normalDataUint);
    computeNormalMapTime.stop();

    // Get the color data and convert it from RGBA to RGB.
    TimeMeasurement captureColorFrameTime("capture color frame");
    uint32_t frameWidth = 0, frameHeight = 0;
    runtime->get_frame_width_and_height(&frameWidth, &frameHeight);
    uint8_t* colorDataRgba = new uint8_t[frameWidth * frameHeight * 4];
    uint8_t* colorData = new uint8_t[frameWidth * frameHeight * 3];
    runtime->capture_screenshot(colorDataRgba);
    int frameSize = static_cast<int>(frameWidth * frameHeight);
    #pragma omp parallel for
    for (int i = 0; i < frameSize; i++) {
        colorData[i*3] = colorDataRgba[i*4];
        colorData[i*3+1] = colorDataRgba[i*4+1];
        colorData[i*3+2] = colorDataRgba[i*4+2];
    }
    delete[] colorDataRgba;
    captureColorFrameTime.stop();

    // Save the frame data to a set of files.
    TimeMeasurement saveImagesTime("save images");
    std::string filenameColor, filenameDepth, filenameNormal;
    std::string frameIdxStr = toString(frame_idx);
#if defined(WRITE_PNG) && WRITE_PNG != 0
    const std::string fileExtension = ".png";
#else
    const std::string fileExtension = ".raw";
#endif
    if (grabber_state.onlyOneScreenshot) {
        filenameColor = grabber_state.screenshotsDirectory + "color_" + frameIdxStr + fileExtension;
        filenameDepth = grabber_state.screenshotsDirectory + "depth_" + frameIdxStr + fileExtension;
        filenameNormal = grabber_state.screenshotsDirectory + "normal_" + frameIdxStr + fileExtension;
    } else {
        filenameColor = grabber_state.screenshotsColorDirectory + frameIdxStr + fileExtension;
        filenameDepth = grabber_state.screenshotsDepthDirectory + frameIdxStr + fileExtension;
        filenameNormal = grabber_state.screenshotsNormalDirectory + frameIdxStr + fileExtension;
    }
    // Save the images to the disk in parallel (this can bring a huge speed-up due to the PNG encoding step being slow).
    #pragma omp parallel sections num_threads(3)
    {
        #pragma omp section
        {
            TimeMeasurement saveDepthImageTime("save depth image");
            saveImage16Bit(
                    filenameDepth, depth_stencil_desc.texture.width, depth_stencil_desc.texture.height,
                    u16Data, 1);
            saveDepthImageTime.stop();
        }

        #pragma omp section
        {
            TimeMeasurement saveNormalImageTime("save normal image");
            saveImage8Bit(
                    filenameNormal, depth_stencil_desc.texture.width, depth_stencil_desc.texture.height,
                    normalDataUint, 3);
            saveNormalImageTime.stop();
        }

        #pragma omp section
        {
            TimeMeasurement saveColorImageTime("save color image");
            saveImage8Bit(
                    filenameColor, frameWidth, frameHeight, colorData, 3);
            saveColorImageTime.stop();
        }
    }
    saveImagesTime.stop();

    // Delete all auxiliary CPU buffers.
    TimeMeasurement deleteAuxDataTime("delete aux data");
    delete[] u16Data;
    delete[] depthData;
    delete[] normalDataUint;
    delete[] colorData;
    deleteAuxDataTime.stop();

    frame_idx++;
}