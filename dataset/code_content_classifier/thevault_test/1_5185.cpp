bool ts::TunerArgs::configureTuner(Tuner& tuner, Report& report) const
{
    if (tuner.isOpen()) {
        report.error(u"tuner is already open");
        return false;
    }

    // These options shall be set before open().
#if defined(TS_WINDOWS)
    tuner.setReceiverFilterName(receiver_name);
#endif

    // Open DVB tuner. Use first device by default (if device name is empty).
    if (!tuner.open(device_name, _info_only, report)) {
        return false;
    }

    // Set configuration parameters.
    if (!_info_only) {
        tuner.setSignalTimeout(signal_timeout);
        if (!tuner.setReceiveTimeout(receive_timeout, report)) {
            tuner.close(NULLREP);
            return false;
        }
#if defined(TS_LINUX)
        tuner.setSignalPoll(Tuner::DEFAULT_SIGNAL_POLL);
        tuner.setDemuxBufferSize(demux_buffer_size);
#elif defined(TS_WINDOWS)
        tuner.setSinkQueueSize(demux_queue_size);
#endif
    }

    return true;
}