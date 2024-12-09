uint32_t LocationApiPbMsgConv::getLocationCapabilitiesMaskFromPB(
        const uint32_t &pbLocCapabMask) const {
    uint32_t locCapabMask = 0;
    if (pbLocCapabMask & PB_LOCATION_CAPS_TIME_BASED_TRACKING_BIT) {
        locCapabMask |= LOCATION_CAPABILITIES_TIME_BASED_TRACKING_BIT;
    }
    if (pbLocCapabMask & PB_LOCATION_CAPS_TIME_BASED_BATCHING_BIT) {
        locCapabMask |= LOCATION_CAPABILITIES_TIME_BASED_BATCHING_BIT;
    }
    if (pbLocCapabMask & PB_LOCATION_CAPS_DISTANCE_BASED_TRACKING_BIT) {
        locCapabMask |= LOCATION_CAPABILITIES_DISTANCE_BASED_TRACKING_BIT;
    }
    if (pbLocCapabMask & PB_LOCATION_CAPS_DISTANCE_BASED_BATCHING_BIT) {
        locCapabMask |= LOCATION_CAPABILITIES_DISTANCE_BASED_BATCHING_BIT;
    }
    if (pbLocCapabMask & PB_LOCATION_CAPS_GEOFENCE_BIT) {
        locCapabMask |= LOCATION_CAPABILITIES_GEOFENCE_BIT;
    }
    if (pbLocCapabMask & PB_LOCATION_CAPS_OUTDOOR_TRIP_BATCHING_BIT) {
        locCapabMask |= LOCATION_CAPABILITIES_OUTDOOR_TRIP_BATCHING_BIT;
    }
    LocApiPb_LOGv("LocApiPB: pbLocCapabMask:%x, locCapabMask:%x", pbLocCapabMask, locCapabMask);
    return locCapabMask;
}