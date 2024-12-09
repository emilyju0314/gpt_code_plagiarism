bool ts::TunerArgs::resolveChannel(const DeliverySystemSet& systems, Report& report)
{
    if (channel_name.empty()) {
        // No channel name to resolve.
        return true;
    }
    else {
        ChannelFile file;
        return file.load(tuning_file_name, report) && file.serviceToTuning(*this, systems, channel_name, false, report);
    }
}