LegacySampleAircraft(const char* inICAOCode,
                         const char* inAirline,
                         const char* inLivery,
                         XPMPPlaneID _modeS_id = 0,
                         const char* inModelName = nullptr) :
    XPCAircraft(inICAOCode, inAirline, inLivery, _modeS_id, inModelName) {}