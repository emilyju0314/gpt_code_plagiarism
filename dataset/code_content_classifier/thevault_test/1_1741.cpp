[[nodiscard]] std::string
    compile_name(std::string_view name, std::uint32_t technique_index, graphics::vertex_layout const &renderable_vertex_layout, graphics::PRIMITIVE_TOPOLOGY primitive_topology)
    {
        auto vertex_layout_name = graphics::to_string(renderable_vertex_layout);
        auto primitive_input_name = graphics::to_string(primitive_topology);

        auto full_name = fmt::format("{}.{}.{}.{}"s, name, technique_index, vertex_layout_name, primitive_input_name);

        const boost::uuids::name_generator_sha1 gen(boost::uuids::ns::dns());

        return boost::uuids::to_string(gen(full_name));
    }