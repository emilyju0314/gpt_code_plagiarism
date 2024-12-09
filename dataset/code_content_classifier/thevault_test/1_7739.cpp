void LocApiV02::convertGnssConestellationMask(
        qmiLocGNSSConstellEnumT_v02 qmiConstellationEnum,
        GnssConstellationTypeMask& constellationMask) {

    constellationMask = 0x0;
    if (qmiConstellationEnum & eQMI_SYSTEM_GPS_V02) {
        constellationMask |= GNSS_CONSTELLATION_TYPE_GPS_BIT;
    }

    if (qmiConstellationEnum & eQMI_SYSTEM_GLO_V02) {
        constellationMask |= GNSS_CONSTELLATION_TYPE_GLONASS_BIT;
    }

    if (qmiConstellationEnum & eQMI_SYSTEM_BDS_V02) {
        constellationMask |= GNSS_CONSTELLATION_TYPE_BEIDOU_BIT;
    }

    if (qmiConstellationEnum & eQMI_SYSTEM_GAL_V02) {
        constellationMask |= GNSS_CONSTELLATION_TYPE_GALILEO_BIT;
    }

    if (qmiConstellationEnum & eQMI_SYSTEM_QZSS_V02) {
        constellationMask |= GNSS_CONSTELLATION_TYPE_QZSS_BIT;
    }

    if (qmiConstellationEnum & eQMI_SYSTEM_NAVIC_V02) {
        constellationMask |= GNSS_CONSTELLATION_TYPE_NAVIC_BIT;
    }
}