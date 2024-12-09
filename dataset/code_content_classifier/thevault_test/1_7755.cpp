int LocationApiPbMsgConv::pbConvertToGnssConfigRobustLocation(
        const PBGnssConfigRobustLocation &pbGnssCfgRobLoc,
        GnssConfigRobustLocation &gnssCfgRobLoc) const {
    // uint32 validMask = 1; - bitwise OR of PBGnssConfigRobustLocationValidMask
    gnssCfgRobLoc.validMask = (GnssConfigRobustLocationValidMask)
            getGnssConfigRobustLocationValidMaskFromPB(pbGnssCfgRobLoc.validmask());

    // bool enabled = 2;
    gnssCfgRobLoc.enabled = pbGnssCfgRobLoc.enabled();

    // bool enabledForE911 = 3;
    gnssCfgRobLoc.enabledForE911 = pbGnssCfgRobLoc.enabledfore911();

    // PBGnssConfigRobustLocationVersion version = 4;
    // >> uint32 major = 1;
    // >> uint32 minor = 2;
    gnssCfgRobLoc.version.major = pbGnssCfgRobLoc.version().major();
    gnssCfgRobLoc.version.minor = pbGnssCfgRobLoc.version().minor();

    LOC_LOGd("LocApiPB: pbGnssCfgRobLoc - CfgRobustLocMask:%x, Enabled:%d, EnabForE911:%d, "\
           "MajorVer:%d, MinorVer:%d", gnssCfgRobLoc.validMask, gnssCfgRobLoc.enabled,
           gnssCfgRobLoc.enabledForE911, gnssCfgRobLoc.version.major, gnssCfgRobLoc.version.minor);
    return 0;
}