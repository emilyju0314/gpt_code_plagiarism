pbf_writer(pbf_writer& parent_writer, pbf_tag_type tag, std::size_t size=0) :
        m_data(parent_writer.m_data),
        m_parent_writer(&parent_writer),
        m_pos(0) {
        m_parent_writer->open_submessage(tag, size);
    }