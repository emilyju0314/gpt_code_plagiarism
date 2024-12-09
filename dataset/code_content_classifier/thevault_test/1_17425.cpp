static other_fields_t to_dictionary(std::string_view const value_pairs)
    {
        other_fields_t ret;

        for (std::string_view const pair : value_pairs | detail::eager_split(',', true))
        {
            auto pair_split = pair | detail::eager_split('=');
            auto it1        = pair_split.begin();
            auto it2        = std::ranges::next(it1);
            auto it3        = std::ranges::next(it2); // TODO whats going on here?

            if (it1 == std::default_sentinel || it2 == std::default_sentinel) //|| it3 != std::default_sentinel)
            {
                throw format_error{"Could not parse the following string into a dictionary: ", pair};
            }

            ret[static_cast<std::string>(*it1)] = static_cast<std::string>(*it2);
        }

        return ret;
    }