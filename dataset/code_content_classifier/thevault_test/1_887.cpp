bool retrieve_commandline_arguments(
            hpx::program_options::options_description const& app_options,
            hpx::program_options::variables_map& vm)
        {
            // The command line for this application instance is available from
            // this configuration section:
            //
            //     [hpx]
            //     cmd_line=....
            //
            std::string cmdline;

            hpx::util::section& cfg = hpx::get_runtime().get_config();
            if (cfg.has_entry("hpx.cmd_line"))
                cmdline = cfg.get_entry("hpx.cmd_line");

            return hpx::local::detail::parse_commandline(
                cfg, app_options, cmdline, vm, allow_unregistered);
        }