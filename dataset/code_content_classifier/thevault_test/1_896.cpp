std::string diagnostic_information(hpx::exception_info const& xi)
    {
        int const verbosity = util::from_string<int>(
            get_config_entry("hpx.exception_verbosity", "2"));

        std::ostringstream strm;
        strm << "\n";

        // add full build information
        if (verbosity >= 2)
        {
            strm << full_build_string();

            std::string const* env = xi.get<hpx::detail::throw_env>();
            if (env && !env->empty())
                strm << "{env}: " << *env;
        }

        if (verbosity >= 1)
        {
            std::string const* back_trace =
                xi.get<hpx::detail::throw_stacktrace>();
            if (back_trace && !back_trace->empty())
            {
                // FIXME: add indentation to stack frame information
                strm << "{stack-trace}: " << *back_trace << "\n";
            }

            std::uint32_t const* locality =
                xi.get<hpx::detail::throw_locality>();
            if (locality)
                strm << "{locality-id}: " << *locality << "\n";

            std::string const* hostname_ =
                xi.get<hpx::detail::throw_hostname>();
            if (hostname_ && !hostname_->empty())
                strm << "{hostname}: " << *hostname_ << "\n";

            std::int64_t const* pid_ = xi.get<hpx::detail::throw_pid>();
            if (pid_ && -1 != *pid_)
                strm << "{process-id}: " << *pid_ << "\n";

            bool thread_info = false;
            char const* const thread_prefix = "{os-thread}: ";
            std::size_t const* shepherd = xi.get<hpx::detail::throw_shepherd>();
            if (shepherd && std::size_t(-1) != *shepherd)
            {
                strm << thread_prefix << *shepherd;
                thread_info = true;
            }

            std::string thread_name = hpx::get_thread_name();
            if (!thread_info)
                strm << thread_prefix;
            else
                strm << ", ";
            strm << thread_name << "\n";

            std::size_t const* thread_id =
                xi.get<hpx::detail::throw_thread_id>();
            if (thread_id && *thread_id)
            {
                strm << "{thread-id}: ";
                hpx::util::format_to(strm, "{:016x}\n", *thread_id);
            }

            std::string const* thread_description =
                xi.get<hpx::detail::throw_thread_name>();
            if (thread_description && !thread_description->empty())
                strm << "{thread-description}: " << *thread_description << "\n";

            std::string const* state = xi.get<hpx::detail::throw_state>();
            if (state)
                strm << "{state}: " << *state << "\n";

            std::string const* auxinfo = xi.get<hpx::detail::throw_auxinfo>();
            if (auxinfo)
                strm << "{auxinfo}: " << *auxinfo << "\n";
        }

        std::string const* file = xi.get<hpx::detail::throw_file>();
        if (file)
            strm << "{file}: " << *file << "\n";

        long const* line = xi.get<hpx::detail::throw_line>();
        if (line)
            strm << "{line}: " << *line << "\n";

        std::string const* function = xi.get<hpx::detail::throw_function>();
        if (function)
            strm << "{function}: " << *function << "\n";

        // Try a cast to std::exception - this should handle boost.system
        // error codes in addition to the standard library exceptions.
        std::exception const* se = dynamic_cast<std::exception const*>(&xi);
        if (se)
            strm << "{what}: " << se->what() << "\n";

        return strm.str();
    }