bool Anvil::DescriptorSetGroup::bake_descriptor_pool()
{
    Anvil::DescriptorPoolCreateFlags                                                                    flags                    = m_descriptor_pool_create_flags;
    std::unique_lock<std::recursive_mutex>                                                              mutex_lock;
    auto                                                                                                mutex_ptr                = get_mutex();
    std::unordered_map<Anvil::DescriptorType, uint32_t, Anvil::EnumClassHasher<Anvil::DescriptorType> > n_descriptors_needed_map;
    bool                                                                                                result                   = false;

    if (mutex_ptr != nullptr)
    {
        mutex_lock = std::move(
            std::unique_lock<std::recursive_mutex>(*mutex_ptr)
        );
    }

    if (m_descriptor_sets.size() == 0)
    {
        goto end;
    }

    /* Count how many descriptor of what types need to have pool space allocated */
    for (auto& current_ds : m_descriptor_sets)
    {
        const Anvil::DescriptorSetCreateInfo* current_ds_create_info_ptr        = nullptr;
        uint32_t                              n_ds_bindings;
        uint32_t                              variable_descriptor_binding_index = UINT32_MAX;
        uint32_t                              variable_descriptor_binding_size  = 0;

        if (current_ds.second->layout_ptr == nullptr)
        {
            current_ds_create_info_ptr = m_device_ptr->get_dummy_descriptor_set_layout()->get_create_info();
        }
        else
        {
            current_ds_create_info_ptr = current_ds.second->layout_ptr->get_create_info();
        }

        n_ds_bindings = static_cast<uint32_t>(current_ds_create_info_ptr->get_n_bindings() );

        current_ds_create_info_ptr->contains_variable_descriptor_count_binding(&variable_descriptor_binding_index,
                                                                               &variable_descriptor_binding_size);

        for (uint32_t n_ds_binding = 0;
                      n_ds_binding < n_ds_bindings;
                    ++n_ds_binding)
        {
            uint32_t                      ds_binding_array_size;
            Anvil::DescriptorBindingFlags ds_binding_flags;
            uint32_t                      ds_binding_index     = UINT32_MAX;
            Anvil::DescriptorType         ds_binding_type      = Anvil::DescriptorType::UNKNOWN;

            current_ds_create_info_ptr->get_binding_properties_by_index_number(n_ds_binding,
                                                                              &ds_binding_index,
                                                                              &ds_binding_type,
                                                                              &ds_binding_array_size,
                                                                               nullptr,  /* out_opt_stage_flags_ptr                */
                                                                               nullptr,  /* out_opt_immutable_samplers_enabled_ptr */
                                                                              &ds_binding_flags);

            if (ds_binding_index == variable_descriptor_binding_index)
            {
                ds_binding_array_size = variable_descriptor_binding_size;
            }

            if ((ds_binding_flags & Anvil::DescriptorBindingFlagBits::UPDATE_AFTER_BIND_BIT) != 0)
            {
                flags |= Anvil::DescriptorPoolCreateFlagBits::UPDATE_AFTER_BIND_BIT;
            }

            n_descriptors_needed_map[ds_binding_type] += ds_binding_array_size;
        }
    }

    for (auto& current_map_entry : n_descriptors_needed_map)
    {
        current_map_entry.second += m_descriptor_type_properties[current_map_entry.first].n_overhead_allocations;
    }

    /* Verify we can actually create the pool.. */
    if ((flags & Anvil::DescriptorPoolCreateFlagBits::UPDATE_AFTER_BIND_BIT) != 0)
    {
        if (!m_device_ptr->get_extension_info()->ext_descriptor_indexing() )
        {
            anvil_assert(m_device_ptr->get_extension_info()->ext_descriptor_indexing() );

            goto end;
        }
    }

    /* Create the pool */
    {
        auto dp_create_info_ptr = Anvil::DescriptorPoolCreateInfo::create(m_device_ptr,
                                                                          m_n_unique_dses,
                                                                          flags,
                                                                          Anvil::Utils::convert_boolean_to_mt_safety_enum(is_mt_safe() ));

        for (const auto& current_n_descriptors_needed_map_entry : n_descriptors_needed_map)
        {
            dp_create_info_ptr->set_n_descriptors_for_descriptor_type(current_n_descriptors_needed_map_entry.first,
                                                                      current_n_descriptors_needed_map_entry.second);
        }

        m_descriptor_pool_ptr = Anvil::DescriptorPool::create(std::move(dp_create_info_ptr) );
    }

    if (m_descriptor_pool_ptr == nullptr)
    {
        anvil_assert(m_descriptor_pool_ptr != nullptr);

        goto end;
    }

    result = true;
end:
    return result;
}