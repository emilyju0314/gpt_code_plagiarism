bool ts::InputSwitcherArgs::loadArgs(DuckContext& duck, Args& args)
{
    appName = args.appName();
    fastSwitch = args.present(u"fast-switch");
    delayedSwitch = args.present(u"delayed-switch");
    terminate = args.present(u"terminate");
    cycleCount = args.intValue<size_t>(u"cycle", args.present(u"infinite") ? 0 : 1);
    monitor = args.present(u"monitor");
    bufferedPackets = args.intValue<size_t>(u"buffer-packets", DEFAULT_BUFFERED_PACKETS);
    maxInputPackets = std::min(args.intValue<size_t>(u"max-input-packets", DEFAULT_MAX_INPUT_PACKETS), bufferedPackets / 2);
    maxOutputPackets = args.intValue<size_t>(u"max-output-packets", DEFAULT_MAX_OUTPUT_PACKETS);
    const UString remoteName(args.value(u"remote"));
    reusePort = !args.present(u"no-reuse-port");
    sockBuffer = args.intValue<size_t>(u"udp-buffer-size");
    firstInput = args.intValue<size_t>(u"first-input", 0);
    primaryInput = args.intValue<size_t>(u"primary-input", NPOS);
    receiveTimeout = args.intValue<MilliSecond>(u"receive-timeout", primaryInput >= inputs.size() ? 0 : DEFAULT_RECEIVE_TIMEOUT);

    // Check conflicting modes.
    if (args.present(u"cycle") + args.present(u"infinite") + args.present(u"terminate") > 1) {
        args.error(u"options --cycle, --infinite and --terminate are mutually exclusive");
    }
    if (fastSwitch && delayedSwitch) {
        args.error(u"options --delayed-switch and --fast-switch are mutually exclusive");
    }

    // Resolve remote control name.
    if (!remoteName.empty() && remoteServer.resolve(remoteName, args) && !remoteServer.hasPort()) {
        args.error(u"missing UDP port number in --remote");
    }

    // Resolve all allowed remote.
    UStringVector remotes;
    args.getValues(remotes, u"allow");
    allowedRemote.clear();
    for (auto it = remotes.begin(); it != remotes.end(); ++it) {
        const IPAddress addr(*it, args);
        if (addr.hasAddress()) {
            allowedRemote.insert(addr);
        }
    }

    // Load all plugin descriptions. Default output is the standard output file.
    ArgsWithPlugins* pargs = dynamic_cast<ArgsWithPlugins*>(&args);
    if (pargs != nullptr) {
        pargs->getPlugins(inputs, INPUT_PLUGIN);
        pargs->getPlugin(output, OUTPUT_PLUGIN, u"file");
    }
    else {
        inputs.clear();
        output.set(u"file");
    }
    if (inputs.empty()) {
        // If no input plugin is used, used only standard input.
        inputs.push_back(PluginOptions(u"file"));
    }

    // Check validity of input indexes.
    if (firstInput >= inputs.size()) {
        args.error(u"invalid input index for --first-input %d", {firstInput});
    }

    if (primaryInput != NPOS && primaryInput >= inputs.size()) {
        args.error(u"invalid input index for --primary-input %d", {primaryInput});
    }

    return args.valid();
}