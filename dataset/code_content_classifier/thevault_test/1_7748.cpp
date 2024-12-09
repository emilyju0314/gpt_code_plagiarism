bool locClientRegisterEventMask(
    locClientHandleType clientHandle,
    locClientEventMaskType eventRegMask,
    bool bIsMaster)
{
  locClientStatusEnumType status = eLOC_CLIENT_SUCCESS;
  locClientReqUnionType reqUnion;
  qmiLocRegEventsReqMsgT_v02 regEventsReq;

  memset(&regEventsReq, 0, sizeof(regEventsReq));

  regEventsReq.eventRegMask = eventRegMask;
  regEventsReq.clientStrId_valid = true;
  if (bIsMaster) {
      LOC_LOGV("%s:%d] %s", __func__, __LINE__, MASTER_HAL);
      strlcpy(regEventsReq.clientStrId, MASTER_HAL,
              sizeof(regEventsReq.clientStrId));
  }
  else {
      LOC_LOGV("%s:%d] %s", __func__, __LINE__, HAL);
      strlcpy(regEventsReq.clientStrId, HAL,
              sizeof(regEventsReq.clientStrId));
  }

  regEventsReq.clientType_valid = true;
  regEventsReq.clientType = eQMI_LOC_CLIENT_AFW_V02;
  regEventsReq.enablePosRequestNotification_valid = true;
  regEventsReq.enablePosRequestNotification = false;

  reqUnion.pRegEventsReq = &regEventsReq;

  status = locClientSendReq(clientHandle,
                            QMI_LOC_REG_EVENTS_REQ_V02,
                            reqUnion);

  if(eLOC_CLIENT_SUCCESS != status )
  {
    LOC_LOGE("%s:%d] status %s\n", __func__, __LINE__,
             loc_get_v02_client_status_name(status) );
    return false;
  }

  return true;
}