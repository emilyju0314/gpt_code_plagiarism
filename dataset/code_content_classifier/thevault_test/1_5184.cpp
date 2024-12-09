bool ts::TunerArgs::loadArgs(DuckContext& duck, Args& args)
{
    bool status = true;
    TunerArgs::reset();

    // Tuner identification.
    if (args.present(u"adapter") && args.present(u"device-name")) {
        args.error(u"choose either --adapter or --device-name but not both");
        status = false;
    }
    if (args.present(u"device-name")) {
        device_name = args.value(u"device-name");
    }
    else if (args.present(u"adapter")) {
        const int adapter = args.intValue(u"adapter", 0);
#if defined(TS_LINUX)
        device_name.format(u"/dev/dvb/adapter%d", {adapter});
#elif defined(TS_WINDOWS)
        device_name.format(u":%d", {adapter});
#else
        // Does not mean anything, just for error messages.
        device_name.format(u"DVB adapter %d", {adapter});
#endif
    }

#if defined(TS_WINDOWS)
    // Windows-specific tuner options.
    receiver_name = args.value(u"receiver-name");
#endif

    // Tuning options.
    if (!_info_only) {
        // Reception parameters.
        signal_timeout = args.intValue<MilliSecond>(u"signal-timeout", Tuner::DEFAULT_SIGNAL_TIMEOUT / 1000) * 1000;
        receive_timeout = args.intValue<MilliSecond>(u"receive-timeout", receive_timeout); // preserve previous value
#if defined(TS_LINUX)
        demux_buffer_size = args.intValue<size_t>(u"demux-buffer-size", Tuner::DEFAULT_DEMUX_BUFFER_SIZE);
#elif defined(TS_WINDOWS)
        demux_queue_size = args.intValue<size_t>(u"demux-queue-size", Tuner::DEFAULT_SINK_QUEUE_SIZE);
#endif

        // Tuning parameters from superclass.
        status = ModulationArgs::loadArgs(duck, args) && status;

        // Locating the transponder by channel
        channel_name = args.value(u"channel-transponder");
        tuning_file_name = args.value(u"tuning-file");

        // Mutually exclusive methods of locating the channels
        if (!channel_name.empty() && hasModulationArgs()) {
            args.error(u"--channel-transponder and individual tuning options are incompatible");
            status = false;
        }
    }

    return status;
}