bool VkRenderFramework::DeviceCanDraw() {
    InitFramework(NULL, NULL);
    InitState(NULL, NULL, 0);
    InitViewport();
    InitRenderTarget();

    // Draw a triangle that covers the entire viewport.
    char const *vsSource =
        "#version 450\n"
        "\n"
        "vec2 vertices[3];\n"
        "void main() { \n"
        "  vertices[0] = vec2(-10.0, -10.0);\n"
        "  vertices[1] = vec2( 10.0, -10.0);\n"
        "  vertices[2] = vec2( 0.0,   10.0);\n"
        "  gl_Position = vec4(vertices[gl_VertexIndex % 3], 0.0, 1.0);\n"
        "}\n";
    // Draw with a solid color.
    char const *fsSource =
        "#version 450\n"
        "\n"
        "layout(location=0) out vec4 color;\n"
        "void main() {\n"
        "   color = vec4(32.0/255.0);\n"
        "}\n";
    VkShaderObj *vs = new VkShaderObj(m_device, vsSource, VK_SHADER_STAGE_VERTEX_BIT, this);
    VkShaderObj *fs = new VkShaderObj(m_device, fsSource, VK_SHADER_STAGE_FRAGMENT_BIT, this);

    VkPipelineObj *pipe = new VkPipelineObj(m_device);
    pipe->AddShader(vs);
    pipe->AddShader(fs);
    pipe->AddDefaultColorAttachment();

    VkDescriptorSetObj *descriptorSet = new VkDescriptorSetObj(m_device);
    descriptorSet->CreateVKDescriptorSet(m_commandBuffer);

    pipe->CreateVKPipeline(descriptorSet->GetPipelineLayout(), renderPass());

    m_commandBuffer->begin();
    m_commandBuffer->BeginRenderPass(m_renderPassBeginInfo);

    vkCmdBindPipeline(m_commandBuffer->handle(), VK_PIPELINE_BIND_POINT_GRAPHICS, pipe->handle());
    m_commandBuffer->BindDescriptorSet(*descriptorSet);

    VkViewport viewport = m_viewports[0];
    VkRect2D scissors = m_scissors[0];

    vkCmdSetViewport(m_commandBuffer->handle(), 0, 1, &viewport);
    vkCmdSetScissor(m_commandBuffer->handle(), 0, 1, &scissors);

    vkCmdDraw(m_commandBuffer->handle(), 3, 1, 0, 0);

    m_commandBuffer->EndRenderPass();
    m_commandBuffer->end();

    VkSubmitInfo submit_info = {};
    submit_info.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;
    submit_info.commandBufferCount = 1;
    submit_info.pCommandBuffers = &m_commandBuffer->handle();

    vkQueueSubmit(m_device->m_queue, 1, &submit_info, VK_NULL_HANDLE);
    vkQueueWaitIdle(m_device->m_queue);

    auto pixels = m_renderTargets[0]->Read();

    delete descriptorSet;
    delete pipe;
    delete fs;
    delete vs;
    ShutdownFramework();
    return pixels[0][0] == 0x20202020;
}