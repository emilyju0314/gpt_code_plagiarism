uint32_t LocationApiPbMsgConv::getPBMaskForLocationCallbacksMask(const uint32_t &locCbMask) const {
    uint32_t pbLocCbMask = 0;
    if (locCbMask & E_LOC_CB_DISTANCE_BASED_TRACKING_BIT) {
        pbLocCbMask |= PB_E_LOC_CB_DISTANCE_BASED_TRACKING_BIT;
    }
    if (locCbMask & E_LOC_CB_GNSS_LOCATION_INFO_BIT) {
        pbLocCbMask |= PB_E_LOC_CB_GNSS_LOCATION_INFO_BIT;
    }
    if (locCbMask & E_LOC_CB_GNSS_SV_BIT) {
        pbLocCbMask |= PB_E_LOC_CB_GNSS_SV_BIT;
    }
    if (locCbMask & E_LOC_CB_GNSS_NMEA_BIT) {
        pbLocCbMask |= PB_E_LOC_CB_GNSS_NMEA_BIT;
    }
    if (locCbMask & E_LOC_CB_GNSS_DATA_BIT) {
        pbLocCbMask |= PB_E_LOC_CB_GNSS_DATA_BIT;
    }
    if (locCbMask & E_LOC_CB_SYSTEM_INFO_BIT) {
        pbLocCbMask |= PB_E_LOC_CB_SYSTEM_INFO_BIT;
    }
    if (locCbMask & E_LOC_CB_BATCHING_BIT) {
        pbLocCbMask |= PB_E_LOC_CB_BATCHING_BIT;
    }
    if (locCbMask & E_LOC_CB_BATCHING_STATUS_BIT) {
        pbLocCbMask |= PB_E_LOC_CB_BATCHING_STATUS_BIT;
    }
    if (locCbMask & E_LOC_CB_GEOFENCE_BREACH_BIT) {
        pbLocCbMask |= PB_E_LOC_CB_GEOFENCE_BREACH_BIT;
    }
    if (locCbMask & E_LOC_CB_ENGINE_LOCATIONS_INFO_BIT) {
        pbLocCbMask |= PB_E_LOC_CB_ENGINE_LOCATIONS_INFO_BIT;
    }
    if (locCbMask & E_LOC_CB_SIMPLE_LOCATION_INFO_BIT) {
        pbLocCbMask |= PB_E_LOC_CB_SIMPLE_LOCATION_INFO_BIT;
    }
    if (locCbMask & E_LOC_CB_GNSS_MEAS_BIT) {
        pbLocCbMask |= PB_E_LOC_CB_GNSS_MEAS_BIT;
    }
    LocApiPb_LOGv("LocApiPB: locCbMask:%x, pbLocCbMask:%x", locCbMask, pbLocCbMask);
    return pbLocCbMask;
}