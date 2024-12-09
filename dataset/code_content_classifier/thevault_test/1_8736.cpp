static void run_gsck(Proxy *proxy, int argc, char **argv)
{
    // use the master proxy thread to run gstore checker
    if (!MASTER(proxy))
        return;

    // parse command
    variables_map gsck_vm;
    try {
        store(parse_command_line(argc, argv, gsck_desc), gsck_vm);
    } catch (...) {
        fail_to_parse(proxy, argc, argv);
        return;
    }
    notify(gsck_vm);

    // parse options
    if (gsck_vm.count("help")) {
        std::cout << gsck_desc;
        return;
    }

    bool i_enable = gsck_vm.count("-i");
    bool n_enable = gsck_vm.count("-n");

    // no option means enable all
    if (!i_enable && !n_enable) {
        i_enable = true;
        n_enable = true;
    }

    /// do gsck
    Monitor monitor;
    GStoreCheck reply;
    int ret = proxy->gstore_check(reply, monitor, i_enable, n_enable);
    if (ret != 0) {
        logstream(LOG_ERROR) << "Data integrity failed in graph store"
                             << " (" << ret << ")" << LOG_endl;
        return;
    }
    monitor.print_latency();
}