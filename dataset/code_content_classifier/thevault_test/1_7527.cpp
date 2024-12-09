explicit pbf_writer(std::string& data) noexcept :
        m_data(&data),
        m_parent_writer(nullptr),
        m_pos(0) {
    }