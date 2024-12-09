PBELocMsgID LocationApiPbMsgConv::getPBEnumForELocMsgID(const ELocMsgID &eLocMsgId) const {
    PBELocMsgID pbLocMsgId = PB_E_LOCAPI_UNDEFINED_MSG_ID;
    switch (eLocMsgId) {
        case E_LOCAPI_CLIENT_REGISTER_MSG_ID:
            pbLocMsgId = PB_E_LOCAPI_CLIENT_REGISTER_MSG_ID;
            break;
        case E_LOCAPI_CLIENT_DEREGISTER_MSG_ID:
            pbLocMsgId = PB_E_LOCAPI_CLIENT_DEREGISTER_MSG_ID;
            break;
        case E_LOCAPI_CAPABILILTIES_MSG_ID:
            pbLocMsgId = PB_E_LOCAPI_CAPABILILTIES_MSG_ID;
            break;
        case E_LOCAPI_HAL_READY_MSG_ID:
            pbLocMsgId = PB_E_LOCAPI_HAL_READY_MSG_ID;
            break;
        case E_LOCAPI_START_TRACKING_MSG_ID:
            pbLocMsgId = PB_E_LOCAPI_START_TRACKING_MSG_ID;
            break;
        case E_LOCAPI_STOP_TRACKING_MSG_ID:
            pbLocMsgId = PB_E_LOCAPI_STOP_TRACKING_MSG_ID;
            break;
        case E_LOCAPI_UPDATE_CALLBACKS_MSG_ID:
            pbLocMsgId = PB_E_LOCAPI_UPDATE_CALLBACKS_MSG_ID;
            break;
        case E_LOCAPI_UPDATE_TRACKING_OPTIONS_MSG_ID:
            pbLocMsgId = PB_E_LOCAPI_UPDATE_TRACKING_OPTIONS_MSG_ID;
            break;
        case E_LOCAPI_CONTROL_UPDATE_CONFIG_MSG_ID:
            pbLocMsgId = PB_E_LOCAPI_CONTROL_UPDATE_CONFIG_MSG_ID;
            break;
        case E_LOCAPI_CONTROL_DELETE_AIDING_DATA_MSG_ID:
            pbLocMsgId = PB_E_LOCAPI_CONTROL_DELETE_AIDING_DATA_MSG_ID;
            break;
        case E_LOCAPI_CONTROL_UPDATE_NETWORK_AVAILABILITY_MSG_ID:
            pbLocMsgId = PB_E_LOCAPI_CONTROL_UPDATE_NETWORK_AVAILABILITY_MSG_ID;
            break;
        case E_LOCAPI_LOCATION_MSG_ID:
            pbLocMsgId = PB_E_LOCAPI_LOCATION_MSG_ID;
            break;
        case E_LOCAPI_LOCATION_INFO_MSG_ID:
            pbLocMsgId = PB_E_LOCAPI_LOCATION_INFO_MSG_ID;
            break;
        case E_LOCAPI_SATELLITE_VEHICLE_MSG_ID:
            pbLocMsgId = PB_E_LOCAPI_SATELLITE_VEHICLE_MSG_ID;
            break;
        case E_LOCAPI_NMEA_MSG_ID:
            pbLocMsgId = PB_E_LOCAPI_NMEA_MSG_ID;
            break;
        case E_LOCAPI_DATA_MSG_ID:
            pbLocMsgId = PB_E_LOCAPI_DATA_MSG_ID;
            break;
        case E_LOCAPI_GET_GNSS_ENGERY_CONSUMED_MSG_ID:
            pbLocMsgId = PB_E_LOCAPI_GET_GNSS_ENGERY_CONSUMED_MSG_ID;
            break;
        case E_LOCAPI_LOCATION_SYSTEM_INFO_MSG_ID:
            pbLocMsgId = PB_E_LOCAPI_LOCATION_SYSTEM_INFO_MSG_ID;
            break;
        case E_LOCAPI_ENGINE_LOCATIONS_INFO_MSG_ID:
            pbLocMsgId = PB_E_LOCAPI_ENGINE_LOCATIONS_INFO_MSG_ID;
            break;
        case E_LOCAPI_START_BATCHING_MSG_ID:
            pbLocMsgId = PB_E_LOCAPI_START_BATCHING_MSG_ID;
            break;
        case E_LOCAPI_STOP_BATCHING_MSG_ID:
            pbLocMsgId = PB_E_LOCAPI_STOP_BATCHING_MSG_ID;
            break;
        case E_LOCAPI_UPDATE_BATCHING_OPTIONS_MSG_ID:
            pbLocMsgId = PB_E_LOCAPI_UPDATE_BATCHING_OPTIONS_MSG_ID;
            break;
        case E_LOCAPI_BATCHING_MSG_ID:
            pbLocMsgId = PB_E_LOCAPI_BATCHING_MSG_ID;
            break;
        case E_LOCAPI_ADD_GEOFENCES_MSG_ID:
            pbLocMsgId = PB_E_LOCAPI_ADD_GEOFENCES_MSG_ID;
            break;
        case E_LOCAPI_REMOVE_GEOFENCES_MSG_ID:
            pbLocMsgId = PB_E_LOCAPI_REMOVE_GEOFENCES_MSG_ID;
            break;
        case E_LOCAPI_MODIFY_GEOFENCES_MSG_ID:
            pbLocMsgId = PB_E_LOCAPI_MODIFY_GEOFENCES_MSG_ID;
            break;
        case E_LOCAPI_PAUSE_GEOFENCES_MSG_ID:
            pbLocMsgId = PB_E_LOCAPI_PAUSE_GEOFENCES_MSG_ID;
            break;
        case E_LOCAPI_RESUME_GEOFENCES_MSG_ID:
            pbLocMsgId = PB_E_LOCAPI_RESUME_GEOFENCES_MSG_ID;
            break;
        case E_LOCAPI_GEOFENCE_BREACH_MSG_ID:
            pbLocMsgId = PB_E_LOCAPI_GEOFENCE_BREACH_MSG_ID;
            break;
        case E_LOCAPI_MEAS_MSG_ID:
            pbLocMsgId = PB_E_LOCAPI_MEAS_MSG_ID;
            break;
        case E_LOCAPI_PINGTEST_MSG_ID:
            pbLocMsgId = PB_E_LOCAPI_PINGTEST_MSG_ID;
            break;
        case E_INTAPI_CONFIG_CONSTRAINTED_TUNC_MSG_ID:
            pbLocMsgId = PB_E_INTAPI_CONFIG_CONSTRAINTED_TUNC_MSG_ID;
            break;
        case E_INTAPI_CONFIG_POSITION_ASSISTED_CLOCK_ESTIMATOR_MSG_ID:
            pbLocMsgId = PB_E_INTAPI_CONFIG_POSITION_ASSISTED_CLOCK_ESTIMATOR_MSG_ID;
            break;
        case E_INTAPI_CONFIG_SV_CONSTELLATION_MSG_ID:
            pbLocMsgId = PB_E_INTAPI_CONFIG_SV_CONSTELLATION_MSG_ID;
            break;
        case E_INTAPI_CONFIG_AIDING_DATA_DELETION_MSG_ID:
            pbLocMsgId = PB_E_INTAPI_CONFIG_AIDING_DATA_DELETION_MSG_ID;
            break;
        case E_INTAPI_CONFIG_LEVER_ARM_MSG_ID:
            pbLocMsgId = PB_E_INTAPI_CONFIG_LEVER_ARM_MSG_ID;
            break;
        case E_INTAPI_CONFIG_ROBUST_LOCATION_MSG_ID:
            pbLocMsgId = PB_E_INTAPI_CONFIG_ROBUST_LOCATION_MSG_ID;
            break;
        case E_INTAPI_CONFIG_MIN_GPS_WEEK_MSG_ID:
            pbLocMsgId = PB_E_INTAPI_CONFIG_MIN_GPS_WEEK_MSG_ID;
            break;
        case E_INTAPI_CONFIG_DEAD_RECKONING_ENGINE_MSG_ID:
            pbLocMsgId = PB_E_INTAPI_CONFIG_DEAD_RECKONING_ENGINE_MSG_ID;
            break;
        case E_INTAPI_CONFIG_MIN_SV_ELEVATION_MSG_ID:
            pbLocMsgId = PB_E_INTAPI_CONFIG_MIN_SV_ELEVATION_MSG_ID;
            break;
        case E_INTAPI_GET_ROBUST_LOCATION_CONFIG_REQ_MSG_ID:
            pbLocMsgId = PB_E_INTAPI_GET_ROBUST_LOCATION_CONFIG_REQ_MSG_ID;
            break;
        case E_INTAPI_GET_ROBUST_LOCATION_CONFIG_RESP_MSG_ID:
            pbLocMsgId = PB_E_INTAPI_GET_ROBUST_LOCATION_CONFIG_RESP_MSG_ID;
            break;
        case E_INTAPI_GET_MIN_GPS_WEEK_REQ_MSG_ID:
            pbLocMsgId = PB_E_INTAPI_GET_MIN_GPS_WEEK_REQ_MSG_ID;
            break;
        case E_INTAPI_GET_MIN_GPS_WEEK_RESP_MSG_ID:
            pbLocMsgId = PB_E_INTAPI_GET_MIN_GPS_WEEK_RESP_MSG_ID;
            break;
        case E_INTAPI_GET_MIN_SV_ELEVATION_REQ_MSG_ID:
            pbLocMsgId = PB_E_INTAPI_GET_MIN_SV_ELEVATION_REQ_MSG_ID;
            break;
        case E_INTAPI_GET_MIN_SV_ELEVATION_RESP_MSG_ID:
            pbLocMsgId = PB_E_INTAPI_GET_MIN_SV_ELEVATION_RESP_MSG_ID;
            break;
        default:
            break;
    }
    LocApiPb_LOGv("LocApiPB: eLocMsgId:%d, pbLocMsgId:%d", eLocMsgId, pbLocMsgId);
    return pbLocMsgId;
}