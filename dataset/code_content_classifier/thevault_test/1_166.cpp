bool GuiManager::updateBuffers() {
    ImDrawData *imDrawData = ImGui::GetDrawData();


    bool updateCommandBuffers = false;
    // Note: Alignment is done inside buffer creation
    VkDeviceSize vertexBufferSize = imDrawData->TotalVtxCount * sizeof(ImDrawVert);
    VkDeviceSize indexBufferSize = imDrawData->TotalIdxCount * sizeof(ImDrawIdx);

    if ((vertexBufferSize == 0) || (indexBufferSize == 0)) {
        return false;
    }

    // Update buffers only if vertex or index count has been changed compared to current buffer size

    // Vertex buffer
    if ((vertexBuffer.buffer == VK_NULL_HANDLE) || (vertexCount != imDrawData->TotalVtxCount)) {
        vertexBuffer.unmap();
        vertexBuffer.destroy();
        if (VK_SUCCESS !=
            device->createBuffer(VK_BUFFER_USAGE_VERTEX_BUFFER_BIT, VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT,
                                 &vertexBuffer, vertexBufferSize))
            throw std::runtime_error("Failed to create vertex Buffer");
        vertexCount = imDrawData->TotalVtxCount;
        vertexBuffer.map();
        updateCommandBuffers = true;
    }

    // Index buffer
    if ((indexBuffer.buffer == VK_NULL_HANDLE) || (indexCount < imDrawData->TotalIdxCount)) {
        indexBuffer.unmap();
        indexBuffer.destroy();
        if (VK_SUCCESS !=
            device->createBuffer(VK_BUFFER_USAGE_INDEX_BUFFER_BIT, VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT,
                                 &indexBuffer, indexBufferSize))
            throw std::runtime_error("Failed to create index buffer");
        indexCount = imDrawData->TotalIdxCount;
        indexBuffer.map();
        updateCommandBuffers = true;
    }

    // Upload data
    ImDrawVert *vtxDst = (ImDrawVert *) vertexBuffer.mapped;
    ImDrawIdx *idxDst = (ImDrawIdx *) indexBuffer.mapped;

    for (int n = 0; n < imDrawData->CmdListsCount; n++) {
        const ImDrawList *cmd_list = imDrawData->CmdLists[n];
        memcpy(vtxDst, cmd_list->VtxBuffer.Data, cmd_list->VtxBuffer.Size * sizeof(ImDrawVert));
        memcpy(idxDst, cmd_list->IdxBuffer.Data, cmd_list->IdxBuffer.Size * sizeof(ImDrawIdx));
        vtxDst += cmd_list->VtxBuffer.Size;
        idxDst += cmd_list->IdxBuffer.Size;
    }

    // Flush to make writes visible to GPU
    vertexBuffer.flush();
    indexBuffer.flush();

    return updateCommandBuffers;
}