LocationError
LocApiV02::setLPPConfigSync(GnssConfigLppProfileMask profileMask)
{
  LocationError err = LOCATION_ERROR_SUCCESS;
  locClientStatusEnumType result = eLOC_CLIENT_SUCCESS;
  locClientReqUnionType req_union;
  qmiLocSetProtocolConfigParametersReqMsgT_v02 lpp_config_req;
  qmiLocSetProtocolConfigParametersIndMsgT_v02 lpp_config_ind;

  LOC_LOGD("%s:%d]: lpp profile = %u",  __func__, __LINE__, profileMask);

  memset(&lpp_config_req, 0, sizeof(lpp_config_req));
  memset(&lpp_config_ind, 0, sizeof(lpp_config_ind));

  lpp_config_req.lppConfig_valid = 1;
  if (profileMask & GNSS_CONFIG_LPP_PROFILE_USER_PLANE_BIT) {
      lpp_config_req.lppConfig |= QMI_LOC_LPP_CONFIG_ENABLE_USER_PLANE_V02;
  }
  if (profileMask & GNSS_CONFIG_LPP_PROFILE_CONTROL_PLANE_BIT) {
      lpp_config_req.lppConfig |= QMI_LOC_LPP_CONFIG_ENABLE_CONTROL_PLANE_V02;
  }
  if (profileMask & GNSS_CONFIG_LPP_PROFILE_USER_PLANE_OVER_NR5G_SA_BIT) {
      lpp_config_req.lppConfig |= QMI_LOC_LPP_CONFIG_ENABLE_USER_PLANE_OVER_NR5G_SA_V02;
  }
  if (profileMask & GNSS_CONFIG_LPP_PROFILE_CONTROL_PLANE_OVER_NR5G_SA_BIT) {
      lpp_config_req.lppConfig |= QMI_LOC_LPP_CONFIG_ENABLE_CONTROL_PLANE_OVER_NR5G_SA_V02;
  }

  req_union.pSetProtocolConfigParametersReq = &lpp_config_req;

  result = locSyncSendReq(QMI_LOC_SET_PROTOCOL_CONFIG_PARAMETERS_REQ_V02,
                          req_union, LOC_ENGINE_SYNC_REQUEST_LONG_TIMEOUT,
                          QMI_LOC_SET_PROTOCOL_CONFIG_PARAMETERS_IND_V02,
                          &lpp_config_ind);

  if(result != eLOC_CLIENT_SUCCESS ||
     eQMI_LOC_SUCCESS_V02 != lpp_config_ind.status)
  {
    LOC_LOGE ("%s:%d]: Error status = %s, ind..status = %s ",
              __func__, __LINE__,
              loc_get_v02_client_status_name(result),
              loc_get_v02_qmi_status_name(lpp_config_ind.status));
     err = LOCATION_ERROR_GENERAL_FAILURE;
  }

  return err;
}