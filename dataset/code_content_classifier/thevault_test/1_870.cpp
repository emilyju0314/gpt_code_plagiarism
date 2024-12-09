std::ptrdiff_t runtime_configuration::init_stack_size(char const* entryname,
        char const* defaultvaluestr, std::ptrdiff_t defaultvalue) const
    {
        if (util::section const* sec = get_section("hpx.stacks");
            nullptr != sec)
        {
            std::string entry = sec->get_entry(entryname, defaultvaluestr);
            char* endptr = nullptr;
            std::ptrdiff_t val =
                std::strtoll(entry.c_str(), &endptr, /*base:*/ 0);
            return endptr != entry.c_str() ? val : defaultvalue;
        }
        return defaultvalue;
    }