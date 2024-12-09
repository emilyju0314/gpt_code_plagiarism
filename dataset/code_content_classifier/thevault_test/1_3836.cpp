void Anvil::Image::init_page_occupancy(const std::vector<Anvil::SparseImageMemoryRequirements>& in_memory_reqs)
{
    anvil_assert((m_create_info_ptr->get_create_flags() & Anvil::ImageCreateFlagBits::SPARSE_RESIDENCY_BIT) != 0);

    /* First, allocate space for an AspectPageOccupancyData instance for all aspects used by the image.
     *
     * Vulkan may interleave data of more than one aspect in one memory region, so we need to go the extra
     * mile to ensure the same AspectPageOccupancyData structure is assigned to such aspects.
     */
    for (const auto& memory_req : in_memory_reqs)
    {
        AspectPageOccupancyData* occupancy_data_ptr = nullptr;

        for (uint32_t n_aspect_bit = 0;
               (1u << n_aspect_bit) <= memory_req.format_properties.aspect_mask.get_vk();
                    ++n_aspect_bit)
        {
            VkImageAspectFlagBits current_aspect = static_cast<VkImageAspectFlagBits>(1 << n_aspect_bit);

            if ((memory_req.format_properties.aspect_mask.get_vk() & current_aspect) == 0)
            {
                continue;
            }

            if (m_sparse_aspect_page_occupancy.find(static_cast<Anvil::ImageAspectFlagBits>(current_aspect) ) != m_sparse_aspect_page_occupancy.end() )
            {
                occupancy_data_ptr = m_sparse_aspect_page_occupancy.at(static_cast<Anvil::ImageAspectFlagBits>(current_aspect) );

                break;
            }
        }

        if (occupancy_data_ptr == nullptr)
        {
            m_sparse_aspect_page_occupancy_data_items_owned.push_back(
                std::unique_ptr<AspectPageOccupancyData>(new AspectPageOccupancyData() )
            );
        }

        for (uint32_t n_aspect_bit = 0;
               (1u << n_aspect_bit) <= memory_req.format_properties.aspect_mask.get_vk();
                    ++n_aspect_bit)
        {
            Anvil::ImageAspectFlagBits current_aspect = static_cast<Anvil::ImageAspectFlagBits>(1 << n_aspect_bit);

            if ((memory_req.format_properties.aspect_mask & current_aspect) == 0)
            {
                continue;
            }

            m_sparse_aspect_page_occupancy[static_cast<Anvil::ImageAspectFlagBits>(current_aspect)] = m_sparse_aspect_page_occupancy_data_items_owned.back().get();
        }
    }

    /* Next, iterate over each aspect and initialize storage for the mip chain */
    for (auto occupancy_iterator  = m_sparse_aspect_page_occupancy.begin();
              occupancy_iterator != m_sparse_aspect_page_occupancy.end();
            ++occupancy_iterator)
    {
        const Anvil::ImageAspectFlagBits&               current_aspect                = occupancy_iterator->first;
        decltype(m_sparse_aspect_props)::const_iterator current_aspect_props_iterator;
        AspectPageOccupancyData*                        page_occupancy_ptr            = occupancy_iterator->second;
        const auto&                                     plane_index                   = (current_aspect == Anvil::ImageAspectFlagBits::PLANE_1_BIT) ? 1
                                                                                      : (current_aspect == Anvil::ImageAspectFlagBits::PLANE_2_BIT) ? 2
                                                                                                                                                    : 0;
        const auto&                                     plane_memory_reqs             = m_plane_index_to_memory_properties_map.at(plane_index);

        anvil_assert(plane_memory_reqs.alignment != 0);

        if (page_occupancy_ptr->layers.size() > 0)
        {
            /* Already initialized */
            continue;
        }

        if (current_aspect == Anvil::ImageAspectFlagBits::METADATA_BIT)
        {
            /* Don't initialize per-layer occupancy data for metadata aspect */
            continue;
        }

        current_aspect_props_iterator = m_sparse_aspect_props.find(current_aspect);
        anvil_assert(current_aspect_props_iterator != m_sparse_aspect_props.end() );

        anvil_assert(current_aspect_props_iterator->second.granularity.width  >= 1);
        anvil_assert(current_aspect_props_iterator->second.granularity.height >= 1);
        anvil_assert(current_aspect_props_iterator->second.granularity.depth  >= 1);

        /* Initialize storage for layer data.. */
        for (uint32_t n_layer = 0;
                      n_layer < m_create_info_ptr->get_n_layers();
                    ++n_layer)
        {
            page_occupancy_ptr->layers.push_back(AspectPageOccupancyLayerData() );

            auto& current_layer = page_occupancy_ptr->layers.back();

            /* Tail can be, but does not necessarily have to be a part of non-zero layers. Take this into account,
             * when determining how many pages we need to alloc space for it. */
            if (current_aspect_props_iterator->second.mip_tail_size > 0)
            {
                const bool is_single_miptail = (current_aspect_props_iterator->second.flags & Anvil::SparseImageFormatFlagBits::SINGLE_MIPTAIL_BIT) != 0;

                if ((is_single_miptail && n_layer == 0) ||
                    !is_single_miptail)
                {
                    anvil_assert( (current_aspect_props_iterator->second.mip_tail_size % plane_memory_reqs.alignment) == 0);

                    current_layer.n_total_tail_pages = static_cast<uint32_t>(current_aspect_props_iterator->second.mip_tail_size / plane_memory_reqs.alignment);

                    current_layer.tail_occupancy.resize(1 + current_layer.n_total_tail_pages / (sizeof(PageOccupancyStatus) * 8 /* bits in byte */) );
                }
                else
                {
                    current_layer.n_total_tail_pages = 0;
                }
            }
            else
            {
                current_layer.n_total_tail_pages = 0;
            }


            for (const auto& current_mip : m_mipmap_props)
            {
                AspectPageOccupancyLayerMipData mip_data(current_mip.width,
                                                         current_mip.height,
                                                         current_mip.depth,
                                                         current_aspect_props_iterator->second.granularity.width,
                                                         current_aspect_props_iterator->second.granularity.height,
                                                         current_aspect_props_iterator->second.granularity.depth);

                anvil_assert(current_mip.width  >= 1);
                anvil_assert(current_mip.height >= 1);
                anvil_assert(current_mip.depth  >= 1);

                current_layer.mips.push_back(mip_data);
            }
        }
    }
}