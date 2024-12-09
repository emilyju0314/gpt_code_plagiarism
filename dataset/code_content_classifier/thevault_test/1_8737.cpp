void run_console(Proxy *proxy)
{
    // init option descriptions once on each server (by the leader proxy)
    if (LEADER(proxy))
        init_options_desc();

    console_barrier(proxy->tid);
    if (MASTER(proxy))
        std::cout << std::endl
             << "Input \'help\' command to get more information"
             << std::endl
             << std::endl;

    bool once = true;
    while (true) {
        console_barrier(proxy->tid);
        std::string cmd;
        if (MASTER(proxy)) {
            if (enable_oneshot) {
                // one-shot command mode: run the command once and then quit
                if (once) {
                    logstream(LOG_INFO) << "Run one-shot command: " << oneshot_cmd << LOG_endl;
                    cmd = oneshot_cmd;

                    once = false;
                } else {
                    logstream(LOG_INFO) << "Done" << LOG_endl;
                    cmd = "quit";
                }
            } else {
                // interactive mode: print a prompt and retrieve the command
                // skip input with blank
                size_t pos;
                do {
                    std::cout << "wukong> ";
                    std::getline(std::cin, cmd);
                    pos = cmd.find_first_not_of(" \t");
                } while (pos == std::string::npos); // if all are blanks, do again
            }

            // trim input
            size_t pos = cmd.find_first_not_of(" \t"); // trim blanks from head
            cmd.erase(0, pos);
            pos = cmd.find_last_not_of(" \t");  // trim blanks from tail
            cmd.erase(pos + 1, cmd.length() - (pos + 1));


            // send <cmd> to all proxies
            for (int i = 0; i < Global::num_servers; i++) {
                for (int j = 0; j < Global::num_proxies; j++) {
                    if (i == 0 && j == 0) continue ;
                    console_send<std::string>(i, j, cmd);
                }
            }
        } else {
            // recieve <cmd>
            cmd = console_recv<std::string>(proxy->tid);
        }

        // transform the comnmand to (argc, argv)
        CMD2Args cmd2args(cmd);
        int argc = 0;
        char **argv = cmd2args.get_args(argc);


        // run commmand on all proxies according to the keyword
        std::string cmd_type = argv[0];
        try {
            if (cmd_type == "help" || cmd_type == "h") {
                if (MASTER(proxy)) print_help();
            } else if (cmd_type == "quit" || cmd_type == "q") {
                if (LEADER(proxy))
                    exit(0);  // each server exits once (by the leader proxy)
            } else if (cmd_type == "config") {
                run_config(proxy, argc, argv);
            } else if (cmd_type == "logger") {
                run_logger(proxy, argc, argv);
            } else if (cmd_type == "sparql") {  // handle SPARQL queries
                run_sparql(proxy, argc, argv);
            } else if (cmd_type == "sparql-emu") {  // run a SPARQL emulator on each proxy
                run_sparql_emu(proxy, argc, argv);
            } else if (cmd_type == "load") {
                run_load(proxy, argc, argv);
            } else if (cmd_type == "gsck") {
                run_gsck(proxy, argc, argv);
            } else if (cmd_type == "load-stat") {
                run_load_stat(proxy, argc, argv);
            } else if (cmd_type == "store-stat") {
                run_store_stat(proxy, argc, argv);
            } else {
                // the same invalid command dispatch to all proxies, print error
                // msg once
                if (MASTER(proxy)) fail_to_parse(proxy, argc, argv);
            }
        } catch (WukongException &ex) {
            logstream(LOG_ERROR)
                    << "ERRNO " << ex.code() << ": " << ex.what() << LOG_endl;
            fail_to_parse(proxy, argc, argv);
        }
    }
}