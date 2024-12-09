void
    Renderer::render(Component::RenderData const& rRenderData)
    {
        // Use shader
        glUseProgram(rRenderData.m_shaderProgramId);

        for (auto const& rUniformBufferUpdate : rRenderData.m_uniformBufferUpdates)
            updateUniformBuffer(rUniformBufferUpdate);
        rRenderData.m_uniformBufferUpdates.clear();

        for (auto const& rUniformTextureUpdate : rRenderData.m_uniformTextureUpdates)
            updateUniformTexture(rUniformTextureUpdate);

        // Draw vertices
        glBindVertexArray(rRenderData.m_vertexArrayObject);
        glDrawElements(GL_TRIANGLES, rRenderData.m_vertexVisits, GL_UNSIGNED_INT, 0);
    }