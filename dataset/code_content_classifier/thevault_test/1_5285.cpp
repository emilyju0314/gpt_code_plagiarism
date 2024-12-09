bool ts::Tuner::checkTuneParameters(ModulationArgs& params, Report& report) const
{
    // Cannot tune if the device is not open.
    if (!_is_open) {
        report.error(u"tuner not open");
        return false;
    }

    // Get default (preferred) delivery system from tuner when needed.
    if (!params.delivery_system.set()) {
        params.delivery_system = _delivery_systems.preferred();
        if (params.delivery_system == DS_UNDEFINED) {
            report.error(u"no tuning delivery system specified");
            return false;
        }
        else if (_delivery_systems.size() > 1) {
            report.verbose(u"using default deliver system %s", {DeliverySystemEnum.name(params.delivery_system.value())});
        }
    }

    // Check if the delivery system is supported by this tuner.
    if (!_delivery_systems.contains(params.delivery_system.value())) {
        report.error(u"deliver system %s not supported on tuner %s", {DeliverySystemEnum.name(params.delivery_system.value()), _device_name});
        return false;
    }

    // Set all unset tuning parameters to their default value.
    params.setDefaultValues();

    // Check if all specified values are supported on the operating system.
    return
        CheckModVar(params.inversion, u"spectral inversion", SpectralInversionEnum, report) &&
        CheckModVar(params.inner_fec, u"FEC", InnerFECEnum, report) &&
        CheckModVar(params.modulation, u"modulation", ModulationEnum, report) &&
        CheckModVar(params.bandwidth, u"bandwidth", BandWidthEnum, report) &&
        CheckModVar(params.fec_hp, u"FEC", InnerFECEnum, report) &&
        CheckModVar(params.fec_lp, u"FEC", InnerFECEnum, report) &&
        CheckModVar(params.transmission_mode, u"transmission mode", TransmissionModeEnum, report) &&
        CheckModVar(params.guard_interval, u"guard interval", GuardIntervalEnum, report) &&
        CheckModVar(params.hierarchy, u"hierarchy", HierarchyEnum, report) &&
        CheckModVar(params.pilots, u"pilots", PilotEnum, report) &&
        CheckModVar(params.roll_off, u"roll-off factor", RollOffEnum, report);
}