void PlanesCreate ()
{
    // 1. New interface of XPMP2::Aircraft class
    if (!pSamplePlane) try {
        pSamplePlane = new SampleAircraft(PLANE_MODEL[gModelIdxBase][0],  // type
                                          PLANE_MODEL[gModelIdxBase][1],  // airline
                                          PLANE_MODEL[gModelIdxBase][2],  // livery
                                          0xABCDEF);                      // manually set Mode S id
    }
    catch (const XPMP2::XPMP2Error& e) {
        LogMsg("Could not create object of type SampleAircraft: %s", e.what());
        pSamplePlane = nullptr;
    }

    // 2. Subclassing the Legacy XPCAircraft class
    // Creating the plane can now (this is new in XPMP2) throw an exception
    if (!pLegacyPlane) try {
        pLegacyPlane = new LegacySampleAircraft(PLANE_MODEL[(gModelIdxBase+1)%3][0].c_str(),  // type
                                                PLANE_MODEL[(gModelIdxBase+1)%3][1].c_str(),  // airline
                                                PLANE_MODEL[(gModelIdxBase+1)%3][2].c_str(),  // livery
                                                0x123456);                                    // manually set Mode S id
    }
    catch (const XPMP2::XPMP2Error& e) {
        LogMsg("Could not create object of type LegacySampleAircraft: %s", e.what());
        pLegacyPlane = nullptr;
    }

    // 3. Using Standard Legacy C interface
    if (!hStdPlane)
        hStdPlane = XPMPCreatePlane(PLANE_MODEL[(gModelIdxBase+2)%3][0].c_str(),  // type
                                    PLANE_MODEL[(gModelIdxBase+2)%3][1].c_str(),  // airline
                                    PLANE_MODEL[(gModelIdxBase+2)%3][2].c_str(),  // livery
                                    CBPlaneData, NULL);

    // Put a checkmark in front of menu item if planes are visible
    XPLMCheckMenuItem(hMenu, 0, ArePlanesCreated()  ? xplm_Menu_Checked : xplm_Menu_Unchecked);
    XPLMCheckMenuItem(hMenu, 1, gbVisible           ? xplm_Menu_Checked : xplm_Menu_Unchecked);
}