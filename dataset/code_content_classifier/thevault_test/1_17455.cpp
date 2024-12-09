void XPMPEnableAircraftLabels (bool _enable)
{
    // Only do anything if this actually is a change to prevent log spamming
    if (glob.bDrawLabels != _enable) {
        LOG_MSG(logDEBUG, DEBUG_ENABLE_AC_LABELS, _enable ? "enabled" : "disabled");
        glob.bDrawLabels = _enable;
        
        // Start/stop drawing as requested
        if (glob.bDrawLabels)
            TwoDActivate();
        else
            TwoDDeactivate();
    }
}