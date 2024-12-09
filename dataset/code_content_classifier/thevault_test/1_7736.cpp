void LocApiV02 :: eventCb(locClientHandleType /*clientHandle*/,
  uint32_t eventId, locClientEventIndUnionType eventPayload)
{
  LOC_LOGd("event id = 0x%X", eventId);

  switch(eventId)
  {
    //Position Report
    case QMI_LOC_EVENT_POSITION_REPORT_IND_V02:
      reportPosition(eventPayload.pPositionReportEvent);
      break;

    // Satellite report
    case QMI_LOC_EVENT_GNSS_SV_INFO_IND_V02:
      reportSv(eventPayload.pGnssSvInfoReportEvent);
      break;

    // Status report
    case QMI_LOC_EVENT_ENGINE_STATE_IND_V02:
      reportEngineState(eventPayload.pEngineState);
      break;

    case QMI_LOC_EVENT_FIX_SESSION_STATE_IND_V02:
      reportFixSessionState(eventPayload.pFixSessionState);
      break;

    // NMEA
    case QMI_LOC_EVENT_NMEA_IND_V02:
      reportNmea(eventPayload.pNmeaReportEvent);
      break;

    // XTRA request
    case QMI_LOC_EVENT_INJECT_PREDICTED_ORBITS_REQ_IND_V02:
      LOC_LOGD("%s:%d]: XTRA download request\n", __func__,
                    __LINE__);
      reportXtraServerUrl(eventPayload.pInjectPredictedOrbitsReqEvent);
      requestXtraData();
      break;

    // time request
    case QMI_LOC_EVENT_INJECT_TIME_REQ_IND_V02:
      LOC_LOGD("%s:%d]: Time request\n", __func__,
                    __LINE__);
      requestTime();
      break;

    //position request
    case QMI_LOC_EVENT_INJECT_POSITION_REQ_IND_V02:
      LOC_LOGD("%s:%d]: Position request\n", __func__,
                    __LINE__);
      requestLocation();
      break;

    // NI request
    case QMI_LOC_EVENT_NI_NOTIFY_VERIFY_REQ_IND_V02:
      reportNiRequest(eventPayload.pNiNotifyVerifyReqEvent);
      break;

    // AGPS connection request
    case QMI_LOC_EVENT_LOCATION_SERVER_CONNECTION_REQ_IND_V02:
      reportAtlRequest(eventPayload.pLocationServerConnReqEvent);
      break;

    case QMI_LOC_EVENT_GNSS_MEASUREMENT_REPORT_IND_V02:
      LOC_LOGd("GNSS Measurement Report");
      if (mInSession) {
          reportGnssMeasurementData(*eventPayload.pGnssSvRawInfoEvent);
      }
      break;

    case QMI_LOC_EVENT_SV_POLYNOMIAL_REPORT_IND_V02:
      LOC_LOGD("%s:%d]: GNSS SV Polynomial Ind\n", __func__,
               __LINE__);
      reportSvPolynomial(eventPayload.pGnssSvPolyInfoEvent);
      break;

    case QMI_LOC_EVENT_GPS_EPHEMERIS_REPORT_IND_V02:
    case QMI_LOC_EVENT_GLONASS_EPHEMERIS_REPORT_IND_V02:
    case QMI_LOC_EVENT_BDS_EPHEMERIS_REPORT_IND_V02:
    case QMI_LOC_EVENT_GALILEO_EPHEMERIS_REPORT_IND_V02:
    case QMI_LOC_EVENT_QZSS_EPHEMERIS_REPORT_IND_V02:
      reportSvEphemeris(eventId, eventPayload);
      break;

    //Unpropagated position report
    case QMI_LOC_EVENT_UNPROPAGATED_POSITION_REPORT_IND_V02:
      reportPosition(eventPayload.pPositionReportEvent, true);
      break;

    case QMI_LOC_GET_BLACKLIST_SV_IND_V02:
      LOC_LOGd("GET blacklist SV Ind");
      reportGnssSvIdConfig(*eventPayload.pGetBlacklistSvEvent);
      break;

    case QMI_LOC_GET_CONSTELLATION_CONTROL_IND_V02:
      LOC_LOGd("GET constellation Ind");
      reportGnssSvTypeConfig(*eventPayload.pGetConstellationConfigEvent);
      break;

    case  QMI_LOC_EVENT_WIFI_REQ_IND_V02:
      LOC_LOGd("WIFI Req Ind");
      requestOdcpi(*eventPayload.pWifiReqEvent);
      break;

    case QMI_LOC_EVENT_REPORT_IND_V02:
      reportLocEvent(eventPayload.pLocEvent);
      break;

    // System info event regarding next leap second
    case QMI_LOC_SYSTEM_INFO_IND_V02:
      reportSystemInfo(eventPayload.pLocSystemInfoEvent);
      break;

    case QMI_LOC_LOCATION_REQUEST_NOTIFICATION_IND_V02:
      reportLocationRequestNotification(eventPayload.pLocReqNotifEvent);
      break;

    case QMI_LOC_EVENT_GEOFENCE_BREACH_NOTIFICATION_IND_V02:
      LOC_LOGd("Got QMI_LOC_EVENT_GEOFENCE_BREACH_NOTIFICATION_IND_V02");
      geofenceBreachEvent(eventPayload.pGeofenceBreachEvent);
      break;

    case QMI_LOC_EVENT_GEOFENCE_BATCHED_BREACH_NOTIFICATION_IND_V02:
      LOC_LOGd("Got QMI_LOC_EVENT_GEOFENCE_BATCHED_BREACH_NOTIFICATION_IND_V02");
      geofenceBreachEvent(eventPayload.pGeofenceBatchedBreachEvent);
      break;

    case QMI_LOC_EVENT_GEOFENCE_GEN_ALERT_IND_V02:
      geofenceStatusEvent(eventPayload.pGeofenceGenAlertEvent);
      break;

    case QMI_LOC_EVENT_GEOFENCE_BATCHED_DWELL_NOTIFICATION_IND_V02:
      LOC_LOGd("Got QMI_LOC_EVENT_GEOFENCE_BATCHED_DWELL_NOTIFICATION_IND_V02");
      geofenceDwellEvent(eventPayload.pGeofenceBatchedDwellEvent);
      break;

    case QMI_LOC_EVENT_BATCH_FULL_NOTIFICATION_IND_V02:
      LOC_LOGd("Got QMI_LOC_EVENT_BATCH_FULL_NOTIFICATION_IND_V02");
      batchFullEvent(eventPayload.pBatchCount);
      break;

    case QMI_LOC_EVENT_BATCHING_STATUS_IND_V02:
      LOC_LOGd("Got QMI_LOC_EVENT_BATCHING_STATUS_IND_V02");
      batchStatusEvent(eventPayload.pBatchingStatusEvent);
      break;

    case QMI_LOC_EVENT_DBT_POSITION_REPORT_IND_V02:
      LOC_LOGd("Got QMI_LOC_EVENT_DBT_POSITION_REPORT_IND_V02");
      onDbtPosReportEvent(eventPayload.pDbtPositionReportEvent);
      break;

  }
}