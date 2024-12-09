void Anvil::Image::on_memory_backing_opaque_update(uint32_t            in_n_plane,
                                                   VkDeviceSize        in_resource_offset,
                                                   VkDeviceSize        in_size,
                                                   Anvil::MemoryBlock* in_memory_block_ptr,
                                                   VkDeviceSize        in_memory_block_start_offset,
                                                   bool                in_memory_block_owned_by_image)
{
    const bool is_unbinding = (in_memory_block_ptr == nullptr);

    /* Sanity checks */
    anvil_assert((m_create_info_ptr->get_create_flags() & Anvil::ImageCreateFlagBits::SPARSE_BINDING_BIT) != 0);

    if (in_memory_block_ptr != nullptr)
    {
        anvil_assert(in_memory_block_ptr->get_create_info_ptr()->get_size() <= in_memory_block_start_offset + in_size);
    }

    if ((m_create_info_ptr->get_create_flags() & Anvil::ImageCreateFlagBits::SPARSE_RESIDENCY_BIT) == 0)
    {
        /* Non-resident image: underlying memory is viewed as an opaque linear region. */
        PerPlaneMemoryProperties* plane_memory_reqs_ptr = &m_plane_index_to_memory_properties_map.at(in_n_plane);

        plane_memory_reqs_ptr->page_tracker_ptr->set_binding(in_memory_block_ptr,
                                                             in_memory_block_start_offset,
                                                             in_resource_offset,
                                                             in_size);
    }
    else
    {
        /* The following use cases are expected to make us reach this block:
         *
         * 1) Application is about to bind a memory backing to all tiles (of a single plane) OR unbind memory backing
         *    from all tiles forming all aspects at once.
         *
         * 2) Application wants to bind (or unbind) a memory backing to/from miptail tile(s).
         *
         * 3) Anvil::Image has requested to bind memory to the metadata aspect. At the moment, this can only
         *    be invoked from within the wrapper's code, and the memory block used for the operation is owned
         *    by the Image wrapper, so there's nothing we need to do here.
         */
        bool is_miptail_tile_binding_operation = false;
        auto metadata_aspect_iterator          = m_sparse_aspect_props.find(Anvil::ImageAspectFlagBits::METADATA_BIT);

        if (metadata_aspect_iterator != m_sparse_aspect_props.end() )
        {
            /* Handle case 3) */
            if (in_resource_offset == metadata_aspect_iterator->second.mip_tail_offset &&
                in_size            == metadata_aspect_iterator->second.mip_tail_size)
            {
                anvil_assert(m_metadata_memory_block_ptr == nullptr);
                anvil_assert(in_memory_block_owned_by_image);

                m_metadata_memory_block_ptr = MemoryBlockUniquePtr(in_memory_block_ptr,
                                                                   std::default_delete<MemoryBlock>() );

                return;
            }
            else
            {
                /* TODO: We do not currently support cases where the application tries to bind its own memory
                 *       block to the metadata aspect.
                 */
                anvil_assert(in_resource_offset < metadata_aspect_iterator->second.mip_tail_offset);
            }
        }

        /* Handle case 2) */
        for (auto aspect_iterator  = m_sparse_aspect_page_occupancy.begin();
                  aspect_iterator != m_sparse_aspect_page_occupancy.end()   && !is_miptail_tile_binding_operation;
                ++aspect_iterator)
        {
            Anvil::ImageAspectFlagBits         current_aspect       = aspect_iterator->first;
            const SparseImageAspectProperties& current_aspect_props = m_sparse_aspect_props.at(current_aspect);
            auto                               occupancy_data_ptr   = aspect_iterator->second;

            ANVIL_REDUNDANT_VARIABLE_CONST(current_aspect_props);

            if (in_size == current_aspect_props.mip_tail_size)
            {
                for (uint32_t n_layer = 0;
                              n_layer < m_create_info_ptr->get_n_layers();
                            ++n_layer)
                {
                    auto& current_layer = occupancy_data_ptr->layers.at(n_layer);

                    if (in_resource_offset == current_aspect_props.mip_tail_offset + current_aspect_props.mip_tail_stride * n_layer)
                    {
                        is_miptail_tile_binding_operation = true;

                        memset(&current_layer.tail_occupancy[0],
                               (!is_unbinding) ? ~0 : 0,
                               current_layer.tail_occupancy.size() * sizeof(current_layer.tail_occupancy[0]));

                        if (!is_unbinding)
                        {
                            current_layer.tail_pages_per_binding[in_memory_block_ptr] = current_layer.n_total_tail_pages;
                        }
                        else
                        {
                            current_layer.tail_pages_per_binding.clear();
                        }

                        break;
                    }
                }
            }
        }

        /* If not case 2) and 3), this has got to be case 1) */
        if (!is_miptail_tile_binding_operation)
        {
            for (auto aspect_iterator  = m_sparse_aspect_page_occupancy.begin();
                      aspect_iterator != m_sparse_aspect_page_occupancy.end();
                    ++aspect_iterator)
            {
                auto occupancy_data_ptr = aspect_iterator->second;

                for (auto& current_layer : occupancy_data_ptr->layers)
                {
                    if (in_resource_offset == 0)
                    {
                        for (auto& current_mip : current_layer.mips)
                        {
                            const uint32_t n_mip_tiles = static_cast<uint32_t>(current_mip.tile_to_block_mappings.size() );

                            for (uint32_t n_mip_tile = 0;
                                          n_mip_tile < n_mip_tiles;
                                        ++n_mip_tile)
                            {
                                current_mip.tile_to_block_mappings.at(n_mip_tile) = in_memory_block_ptr;
                            }
                        }
                    }
                }
            }
        }
    }

    if (in_memory_block_owned_by_image)
    {
        m_memory_blocks_owned.push_back(
            Anvil::MemoryBlockUniquePtr(in_memory_block_ptr,
                                       std::default_delete<MemoryBlock>() )
        );
    }
}