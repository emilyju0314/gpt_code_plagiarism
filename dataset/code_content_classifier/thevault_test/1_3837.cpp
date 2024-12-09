void Anvil::Image::init_mipmap_props()
{
    uint32_t current_mipmap_size[3] =
    {
        m_create_info_ptr->get_base_mip_width (),
        m_create_info_ptr->get_base_mip_height(),
        m_create_info_ptr->get_base_mip_depth ()
    };

    anvil_assert(m_n_mipmaps           != 0);
    anvil_assert(m_mipmap_props.size() == 0);

    for (uint32_t mipmap_level = 0;
                  mipmap_level < m_n_mipmaps;
                ++mipmap_level)
    {
        m_mipmap_props.push_back(Mipmap(current_mipmap_size[0],
                                        current_mipmap_size[1],
                                        current_mipmap_size[2]) );

        current_mipmap_size[0] /= 2;
        current_mipmap_size[1] /= 2;

        if (m_create_info_ptr->get_type() == Anvil::ImageType::_3D)
        {
            current_mipmap_size[2] /= 2;
        }

        if (current_mipmap_size[0] < 1)
        {
            current_mipmap_size[0] = 1;
        }

        if (current_mipmap_size[1] < 1)
        {
            current_mipmap_size[1] = 1;
        }

        if (current_mipmap_size[2] < 1)
        {
            current_mipmap_size[2] = 1;
        }
    }
}