void LocApiV02 :: reportAtlRequest(
  const qmiLocEventLocationServerConnectionReqIndMsgT_v02 * server_request_ptr)
{
  uint32_t connHandle = server_request_ptr->connHandle;

  if (server_request_ptr->requestType == eQMI_LOC_SERVER_REQUEST_OPEN_V02)
  {
    LocAGpsType agpsType = LOC_AGPS_TYPE_ANY;
    LocApnTypeMask apnTypeMask = 0;

    switch (server_request_ptr->wwanType)
    {
      case eQMI_LOC_WWAN_TYPE_INTERNET_V02:
        agpsType = LOC_AGPS_TYPE_WWAN_ANY;
        break;
      case eQMI_LOC_WWAN_TYPE_AGNSS_V02:
        agpsType = LOC_AGPS_TYPE_SUPL;
        break;
      case eQMI_LOC_WWAN_TYPE_AGNSS_EMERGENCY_V02:
        agpsType = LOC_AGPS_TYPE_SUPL_ES;
        break;
      default:
        agpsType = LOC_AGPS_TYPE_WWAN_ANY;
        break;
    }

    if (server_request_ptr->apnTypeMask_valid) {
        apnTypeMask = convertQmiLocApnTypeMask(server_request_ptr->apnTypeMask);
    }
    LOC_LOGd("handle=%d agpsType=0x%X apnTypeMask=0x%X",
        connHandle, agpsType, apnTypeMask);
    requestATL(connHandle, agpsType, apnTypeMask);
  }
  // service the ATL close request
  else if (server_request_ptr->requestType == eQMI_LOC_SERVER_REQUEST_CLOSE_V02)
  {
    releaseATL(connHandle);
  }
}