bool list_counter_info(
        performance_counters::counter_info const& info, error_code& ec)
    {
        // compose the information to be printed for each of the counters
        std::ostringstream strm;

        strm << std::string(78, '-') << '\n';
        strm << "fullname: " << info.fullname_ << '\n';
        strm << "helptext: " << info.helptext_ << '\n';
        strm << "type:     "
             << performance_counters::get_counter_type_name(info.type_) << '\n';

        strm << "version:  ";    // 0xMMmmrrrr
        hpx::util::format_to(strm, "{}.{}.{}\n", info.version_ / 0x1000000,
            info.version_ / 0x10000 % 0x100, info.version_ % 0x10000);
        strm << std::string(78, '-') << '\n';

        print(strm.str(), ec);

        if (&ec != &throws)
            ec = make_success_code();
        return true;
    }