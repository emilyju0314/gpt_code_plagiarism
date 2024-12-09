XPMPPlaneID XPMPCreatePlaneWithModelName(const char *       inModelName,
                                         const char *       inICAOCode,
                                         const char *       inAirline,
                                         const char *       inLivery,
                                         XPMPPlaneData_f    inDataFunc,
                                         void *             inRefcon,
                                         XPMPPlaneID        inModeS_id)
{
    try {
#ifndef __clang_analyzer__
        LegacyAircraft* pAc = new LegacyAircraft(inICAOCode,
                                                 inAirline,
                                                 inLivery,
                                                 inDataFunc,
                                                 inRefcon,
                                                 inModeS_id,
                                                 inModelName);
        // This is not leaking memory, the pointer is in glob.mapAc as taken care of by the constructor
        return pAc->GetModeS_ID();
#endif
    }
    catch (const XPMP2Error& e) {
        // This might be thrown in case of problems creating the object
        LOG_MSG(logERR, "Could not create plane object for %s/%s/%s/0x%06X/%s: %s",
                inICAOCode  ? inICAOCode    : "<null>",
                inAirline   ? inAirline     : "<null>",
                inLivery    ? inLivery      : "<null>",
                inModeS_id,
                inModelName ? inModelName   : "<null>",
                e.what());
        return 0;
    }
}