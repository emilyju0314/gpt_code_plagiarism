SampleAircraft(const std::string& _icaoType,
                   const std::string& _icaoAirline,
                   const std::string& _livery,
                   XPMPPlaneID _modeS_id = 0,
                   const std::string& _cslId = "") :
    Aircraft(_icaoType, _icaoAirline, _livery, _modeS_id, _cslId)
    {
        // in our sample implementation, label, radar and info texts
        // are not dynamic. In others, they might be, then update them
        // in UpdatePosition()

        // Label
        label = "XPMP2::Aircraft";
        colLabel[0] = 0.0f;             // green
        colLabel[1] = 1.0f;
        colLabel[2] = 0.0f;

        // Radar
        acRadar.code = 7654;
        acRadar.mode = xpmpTransponderMode_ModeC;

        // informational texts
        strScpy(acInfoTexts.icaoAcType, _icaoType.c_str(), sizeof(acInfoTexts.icaoAcType));
        strScpy(acInfoTexts.icaoAirline, _icaoAirline.c_str(), sizeof(acInfoTexts.icaoAirline));
        strScpy(acInfoTexts.tailNum, "D-EVEL", sizeof(acInfoTexts.tailNum));
    }