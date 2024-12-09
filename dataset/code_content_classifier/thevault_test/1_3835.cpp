void Anvil::GraphicsPipelineManager::GraphicsPipelineData::bake_vk_attributes_and_bindings()
{
    uint32_t n_bindings = 0;

    anvil_assert(input_bindings.size     () == 0);
    anvil_assert(vk_input_attributes.size() == 0);
    anvil_assert(vk_input_bindings.size  () == 0);

    pipeline_create_info_ptr->get_graphics_pipeline_properties(nullptr,     /* out_opt_n_scissors_ptr        */
                                                               nullptr,     /* out_opt_n_viewports_ptr       */
                                                               &n_bindings, /* out_opt_n_vertex_bindings_ptr */
                                                               nullptr,     /* out_opt_renderpass_ptr        */
                                                               nullptr);    /* out_opt_subpass_id_ptr        */

    for (uint32_t n_binding = 0;
                  n_binding < n_bindings;
                ++n_binding)
    {
        /* Identify the binding index we should use for the attribute.
         *
         * If an explicit binding has been specified by the application, this step can be skipped */
        const Anvil::VertexInputAttribute* current_binding_attributes_ptr = nullptr;
        uint32_t                           current_binding_divisor        = 0;
        uint32_t                           current_binding_index          = UINT32_MAX;
        uint32_t                           current_binding_n_attributes   = 0;
        Anvil::VertexInputRate             current_binding_rate           = Anvil::VertexInputRate::UNKNOWN;
        uint32_t                           current_binding_stride         = UINT32_MAX;

        if (!pipeline_create_info_ptr->get_vertex_binding_properties(n_binding,
                                                                    &current_binding_index,
                                                                    &current_binding_stride,
                                                                    &current_binding_rate,
                                                                    &current_binding_n_attributes,
                                                                    &current_binding_attributes_ptr,
            &current_binding_divisor) )
        {
            anvil_assert_fail();

            continue;
        }

        /* Create a new VK binding descriptor for current binding */
        VertexInputBinding              new_binding_anvil;
        VkVertexInputBindingDescription new_binding_vk;

        new_binding_vk.binding   = current_binding_index;
        new_binding_vk.inputRate = static_cast<VkVertexInputRate>(current_binding_rate);
        new_binding_vk.stride    = current_binding_stride;

        new_binding_anvil = VertexInputBinding(new_binding_vk,
                                               current_binding_divisor);

        input_bindings.push_back   (new_binding_anvil);
        vk_input_bindings.push_back(new_binding_vk);

        /* Good to convert the internal attribute descriptor to the Vulkan's input attribute descriptor */
        for (uint32_t n_current_attribute = 0;
                      n_current_attribute < current_binding_n_attributes;
                    ++n_current_attribute)
        {
            const auto&                       current_attribute    = current_binding_attributes_ptr[n_current_attribute];
            VkVertexInputAttributeDescription current_attribute_vk;

            current_attribute_vk.binding  = current_binding_index;
            current_attribute_vk.format   = static_cast<VkFormat>(current_attribute.format);
            current_attribute_vk.location = current_attribute.location;
            current_attribute_vk.offset   = current_attribute.offset_in_bytes;

            /* Cache the descriptor */
            vk_input_attributes.push_back(current_attribute_vk);
        }
    }
}