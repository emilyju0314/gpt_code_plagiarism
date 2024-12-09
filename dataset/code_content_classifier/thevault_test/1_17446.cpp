void XPMPSetDefaultPlaneICAO(const char* _acIcaoType,
                             const char* _carIcaoType)
{
    // Plane default
    if (_acIcaoType) {
        glob.defaultICAO = _acIcaoType;
        LOG_MSG(logINFO, INFO_DEFAULT_ICAO, _acIcaoType);
    }

    // Car identification
    if (_carIcaoType) {
        glob.carIcaoType = _carIcaoType; 
        LOG_MSG(logINFO, INFO_CAR_ICAO, _carIcaoType);
    }
}