static float* copyDepthDataToCpu(
        device* const device, resource staging_texture, resource_desc staging_texture_desc,
        resource_desc depth_stencil_desc)
{
    void* depthBufferPtr = nullptr;
    uint32_t row_pitch = 0;
    device->map_resource_pitch(staging_texture, 0, map_access::read_only, &depthBufferPtr, &row_pitch);
    if (!depthBufferPtr) {
        Logfile::get()->fatalError("Failed to map resource to CPU memory!");
    }

    float* depthData = new float[depth_stencil_desc.texture.width * depth_stencil_desc.texture.height];
    if (staging_texture_desc.texture.format == format::r32_float) {
        if (row_pitch == depth_stencil_desc.texture.width * sizeof(float) || row_pitch == 0) {
            std::memcpy(
                    depthData, depthBufferPtr,
                    depth_stencil_desc.texture.width * depth_stencil_desc.texture.height * sizeof(float));
        } else {
            uint8_t* depthDataPtrByte = reinterpret_cast<uint8_t*>(depthData);
            uint8_t* depthBufferPtrByte = reinterpret_cast<uint8_t*>(depthBufferPtr);
            for (uint32_t y = 0; y < depth_stencil_desc.texture.height; y++) {
                std::memcpy(
                        depthDataPtrByte + y * depth_stencil_desc.texture.width * sizeof(float),
                        depthBufferPtrByte + y * row_pitch,
                        depth_stencil_desc.texture.width * sizeof(float));
            }
        }
    } else if (staging_texture_desc.texture.format == format::r24_unorm_x8_uint) {
        uint32_t* u32Data = new uint32_t[depth_stencil_desc.texture.width * depth_stencil_desc.texture.height];
		if (row_pitch == depth_stencil_desc.texture.width * sizeof(float) || row_pitch == 0) {
			std::memcpy(
				u32Data, depthBufferPtr,
				depth_stencil_desc.texture.width * depth_stencil_desc.texture.height * sizeof(uint32_t));
		} else {
			uint8_t* u32DataPtrByte = reinterpret_cast<uint8_t*>(u32Data);
			uint8_t* depthBufferPtrByte = reinterpret_cast<uint8_t*>(depthBufferPtr);
			for (uint32_t y = 0; y < depth_stencil_desc.texture.height; y++) {
				std::memcpy(
					u32DataPtrByte + y * depth_stencil_desc.texture.width * sizeof(uint32_t),
					depthBufferPtrByte + y * row_pitch,
					depth_stencil_desc.texture.width * sizeof(uint32_t));
			}
		}
        for (uint32_t y = 0; y < depth_stencil_desc.texture.height; y++) {
            for (uint32_t x = 0; x < depth_stencil_desc.texture.width; x++) {
                uint32_t i = x + y * depth_stencil_desc.texture.width;
                depthData[i] = float(u32Data[i] & 0xFFFFFFul) / 16777215.0f;
            }
        }
        delete[] u32Data;
    } else if (staging_texture_desc.texture.format == format::r16_unorm) {
        uint16_t* u16Data = new uint16_t[depth_stencil_desc.texture.width * depth_stencil_desc.texture.height];
		if (row_pitch == depth_stencil_desc.texture.width * sizeof(float) || row_pitch == 0) {
			std::memcpy(
				u16Data, depthBufferPtr,
				depth_stencil_desc.texture.width * depth_stencil_desc.texture.height * sizeof(uint16_t));
		} else {
			uint8_t* u16DataPtrByte = reinterpret_cast<uint8_t*>(u16Data);
			uint8_t* depthBufferPtrByte = reinterpret_cast<uint8_t*>(depthBufferPtr);
			for (uint32_t y = 0; y < depth_stencil_desc.texture.height; y++) {
				std::memcpy(
					u16DataPtrByte + y * depth_stencil_desc.texture.width * sizeof(uint16_t),
					depthBufferPtrByte + y * row_pitch,
					depth_stencil_desc.texture.width * sizeof(uint16_t));
			}
		}
		for (uint32_t y = 0; y < depth_stencil_desc.texture.height; y++) {
            for (uint32_t x = 0; x < depth_stencil_desc.texture.width; x++) {
                uint32_t i = x + y * depth_stencil_desc.texture.width;
                depthData[i] = u16Data[i] / 65535.0f;
            }
        }
        delete[] u16Data;
    } else {
        Logfile::get()->fatalError(
                "Error: Invalid texture format (" + std::to_string(int(staging_texture_desc.texture.format)) + ")");
    }

    device->unmap_resource(staging_texture, 0);

    return depthData;
}