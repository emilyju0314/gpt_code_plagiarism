bool runtime_configuration::enable_networking() const
    {
#if defined(HPX_HAVE_NETWORKING)
        if (util::section const* sec = get_section("hpx"); nullptr != sec)
        {
            // get the number of initial localities
            if (hpx::util::get_entry_as<std::uint32_t>(*sec, "localities", 1) >
                1)
            {
                return true;
            }

            // on localities other than locality zero the number of
            // localities might not have been initialized yet
            if (hpx::util::get_entry_as<std::int32_t>(*sec, "node", -1) > 0)
            {
                return true;
            }

            // get whether localities are expected to connect
            if (hpx::util::get_entry_as<std::int32_t>(
                    *sec, "expect_connecting_localities", 0) != 0)
            {
                return true;
            }

            // for any runtime mode except 'console' networking should be
            // enabled as well
            if (hpx::util::get_entry_as<std::string>(
                    *sec, "runtime_mode", "") != "console")
            {
                return true;
            }
        }
#endif
        return false;
    }