void
    update(entt::registry& rRegistry)
    {
        rRegistry.view<Component::Position,
                       Component::UniformModelViewMatrix,
                       Plight::Component::RenderData>().each([&](auto const& rPosition, auto& rUniformModelViewMatrix, auto& rRenderData)
                                                             {
                                                                 Plight::Graphics::UniformBufferUpdateData<float> update;
                                                                 update.m_offset = 12 * sizeof(float);
                                                                 update.m_data = {rPosition.m_value[0] / 10000.0f, rPosition.m_value[1] / 10000.0f};
                                                                 rUniformModelViewMatrix.m_uniformBufferData.m_floatUpdateData = {update};
                                                                 rRenderData.m_uniformBufferUpdates.emplace_back(rUniformModelViewMatrix.m_uniformBufferData);
                                                             });
    }