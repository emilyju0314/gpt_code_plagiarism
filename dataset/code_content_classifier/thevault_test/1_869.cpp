std::string runtime_configuration::get_endian_out() const
    {
        if (util::section const* sec = get_section("hpx.parcel");
            nullptr != sec)
        {
            return sec->get_entry(
                "endian_out", endian::native == endian::big ? "big" : "little");
        }
        return endian::native == endian::big ? "big" : "little";
    }