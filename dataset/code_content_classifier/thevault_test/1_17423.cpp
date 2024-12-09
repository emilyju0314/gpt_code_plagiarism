void parse_column_labels_line(std::string_view const l)
    {
        for (std::string_view field : l | detail::eager_split('\t'))
            column_labels.push_back(static_cast<std::string>(field));
    }