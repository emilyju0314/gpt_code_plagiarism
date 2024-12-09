void ts::InputSwitcherArgs::defineArgs(Args& args) const
{
    args.option(u"allow", 'a', Args::STRING);
    args.help(u"allow",
              u"Specify an IP address or host name which is allowed to send remote commands. "
              u"Several --allow options are allowed. By default, all remote commands are accepted.");

    args.option(u"buffer-packets", 'b', Args::POSITIVE);
    args.help(u"buffer-packets",
              u"Specify the size in TS packets of each input plugin buffer. "
              u"The default is " + UString::Decimal(DEFAULT_BUFFERED_PACKETS) + u" packets.");

    args.option(u"cycle", 'c', Args::POSITIVE);
    args.help(u"cycle",
              u"Specify how many times to repeat the cycle through all input plugins in sequence. "
              u"By default, all input plugins are executed in sequence only once (--cycle 1). "
              u"The options --cycle, --infinite and --terminate are mutually exclusive.");

    args.option(u"delayed-switch", 'd');
    args.help(u"delayed-switch",
              u"Perform delayed input switching. When switching from one input plugin to another one, "
              u"the second plugin is started first. Packets from the first plugin continue to be "
              u"output while the second plugin is starting. Then, after the second plugin starts to "
              u"receive packets, the switch occurs: packets are now fetched from the second plugin. "
              u"Finally, after the switch, the first plugin is stopped.");

    args.option(u"fast-switch", 'f');
    args.help(u"fast-switch",
              u"Perform fast input switching. All input plugins are started at once and they "
              u"continuously receive packets in parallel. Packets are dropped, except for the "
              u"current input plugin. This option is typically used when all inputs are live "
              u"streams on distinct devices (not the same DVB tuner for instance).\n\n"
              u"By default, only one input plugin is started at a time. When switching, "
              u"the current input is first stopped and then the next one is started.");

    args.option(u"first-input", 0, Args::UNSIGNED);
    args.help(u"first-input",
              u"Specify the index of the first input plugin to start. "
              u"By default, the first plugin (index 0) is used.");

    args.option(u"infinite", 'i');
    args.help(u"infinite", u"Infinitely repeat the cycle through all input plugins in sequence.");

    args.option(u"max-input-packets", 0, Args::POSITIVE);
    args.help(u"max-input-packets",
              u"Specify the maximum number of TS packets to read at a time. "
              u"This value may impact the switch response time. "
              u"The default is " + UString::Decimal(DEFAULT_MAX_INPUT_PACKETS) + u" packets. "
              u"The actual value is never more than half the --buffer-packets value.");

    args.option(u"max-output-packets", 0, Args::POSITIVE);
    args.help(u"max-output-packets",
              u"Specify the maximum number of TS packets to write at a time. "
              u"The default is " + UString::Decimal(DEFAULT_MAX_OUTPUT_PACKETS) + u" packets.");

    args.option(u"monitor", 'm');
    args.help(u"monitor",
              u"Continuously monitor the system resources which are used by tsswitch. "
              u"This includes CPU load, virtual memory usage. Useful to verify the "
              u"stability of the application.");

    args.option(u"primary-input", 'p', Args::UNSIGNED);
    args.help(u"primary-input",
              u"Specify the index of the input plugin which is considered as primary "
              u"or preferred. This input plugin is always started, never stopped, even "
              u"without --fast-switch. When no packet is received on this plugin, the "
              u"normal switching rules apply. However, as soon as packets are back on "
              u"the primary input, the reception is immediately switched back to it. "
              u"By default, there is no primary input, all input plugins are equal.");

    args.option(u"no-reuse-port");
    args.help(u"no-reuse-port",
              u"Disable the reuse port socket option for the remote control. "
              u"Do not use unless completely necessary.");

    args.option(u"receive-timeout", 0, Args::UNSIGNED);
    args.help(u"receive-timeout",
              u"Specify a receive timeout in milliseconds. "
              u"When the current input plugin has received no packet within "
              u"this timeout, automatically switch to the next plugin. "
              u"By default, without --primary-input, there is no automatic switch "
              u"when the current input plugin is waiting for packets. With "
              u"--primary-input, the default is " + UString::Decimal(DEFAULT_RECEIVE_TIMEOUT) + u" ms.");

    args.option(u"remote", 'r', Args::STRING);
    args.help(u"remote", u"[address:]port",
              u"Specify the local UDP port which is used to receive remote commands. "
              u"If an optional address is specified, it must be a local IP address of the system. "
              u"By default, there is no remote control.");

    args.option(u"terminate", 't');
    args.help(u"terminate", u"Terminate execution when the current input plugin terminates.");

    args.option(u"udp-buffer-size", 0, Args::UNSIGNED);
    args.help(u"udp-buffer-size",
              u"Specifies the UDP socket receive buffer size (socket option).");
}