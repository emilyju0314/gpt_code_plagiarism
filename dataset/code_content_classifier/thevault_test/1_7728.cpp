void
LocApiV02::informNiResponse(GnssNiResponse userResponse, const void* passThroughData)
{
    sendMsg(new LocApiMsg([this, userResponse, passThroughData] () {

        LocationError err = LOCATION_ERROR_SUCCESS;
        locClientReqUnionType req_union;
        locClientStatusEnumType status;
        qmiLocNiUserRespReqMsgT_v02 ni_resp;
        qmiLocNiUserRespIndMsgT_v02 ni_resp_ind;

        qmiLocEventNiNotifyVerifyReqIndMsgT_v02 *request_pass_back =
            (qmiLocEventNiNotifyVerifyReqIndMsgT_v02 *)passThroughData;

        memset(&ni_resp,0, sizeof(ni_resp));

        memset(&ni_resp_ind,0, sizeof(ni_resp_ind));

        switch (userResponse) {
        case GNSS_NI_RESPONSE_ACCEPT:
            ni_resp.userResp = eQMI_LOC_NI_LCS_NOTIFY_VERIFY_ACCEPT_V02;
            break;
        case GNSS_NI_RESPONSE_DENY:
            ni_resp.userResp = eQMI_LOC_NI_LCS_NOTIFY_VERIFY_DENY_V02;
            break;
        case GNSS_NI_RESPONSE_NO_RESPONSE:
            ni_resp.userResp = eQMI_LOC_NI_LCS_NOTIFY_VERIFY_NORESP_V02;
            break;
        default:
            err = LOCATION_ERROR_INVALID_PARAMETER;
            free((void *)passThroughData);
            return;
        }

        LOC_LOGv("NI response: %d", ni_resp.userResp);

        ni_resp.notificationType = request_pass_back->notificationType;

        // copy SUPL payload from request
        if (1 == request_pass_back->NiSuplInd_valid) {
            ni_resp.NiSuplPayload_valid = 1;
            memcpy(&(ni_resp.NiSuplPayload),
                   &(request_pass_back->NiSuplInd),
                   sizeof(qmiLocNiSuplNotifyVerifyStructT_v02));
        }
        // should this be an "else if"?? we don't need to decide

        // copy UMTS-CP payload from request
        if (1 == request_pass_back->NiUmtsCpInd_valid) {
            ni_resp.NiUmtsCpPayload_valid = 1;
            memcpy(&(ni_resp.NiUmtsCpPayload),
                   &(request_pass_back->NiUmtsCpInd),
                   sizeof(qmiLocNiUmtsCpNotifyVerifyStructT_v02));
        }

        //copy Vx payload from the request
        if (1 == request_pass_back->NiVxInd_valid) {
            ni_resp.NiVxPayload_valid = 1;
            memcpy(&(ni_resp.NiVxPayload),
                   &(request_pass_back->NiVxInd),
                   sizeof(qmiLocNiVxNotifyVerifyStructT_v02));
        }

        // copy Vx service interaction payload from the request
        if (1 == request_pass_back->NiVxServiceInteractionInd_valid) {
            ni_resp.NiVxServiceInteractionPayload_valid = 1;
            memcpy(&(ni_resp.NiVxServiceInteractionPayload),
                   &(request_pass_back->NiVxServiceInteractionInd),
                   sizeof(qmiLocNiVxServiceInteractionStructT_v02));
        }

        // copy Network Initiated SUPL Version 2 Extension
        if (1 == request_pass_back->NiSuplVer2ExtInd_valid) {
            ni_resp.NiSuplVer2ExtPayload_valid = 1;
            memcpy(&(ni_resp.NiSuplVer2ExtPayload),
                   &(request_pass_back->NiSuplVer2ExtInd),
                   sizeof(qmiLocNiSuplVer2ExtStructT_v02));
        }

        // copy SUPL Emergency Notification
        if (request_pass_back->suplEmergencyNotification_valid) {
            ni_resp.suplEmergencyNotification_valid = 1;
            memcpy(&(ni_resp.suplEmergencyNotification),
                   &(request_pass_back->suplEmergencyNotification),
                   sizeof(qmiLocEmergencyNotificationStructT_v02));
        }

        req_union.pNiUserRespReq = &ni_resp;

        status = locSyncSendReq(QMI_LOC_NI_USER_RESPONSE_REQ_V02,
                                req_union, LOC_ENGINE_SYNC_REQUEST_TIMEOUT,
                                QMI_LOC_NI_USER_RESPONSE_IND_V02,
                                &ni_resp_ind);

        if (status != eLOC_CLIENT_SUCCESS ||
            eQMI_LOC_SUCCESS_V02 != ni_resp_ind.status) {

            LOC_LOGe("error! status = %s, ni_resp_ind.status = %s",
                     loc_get_v02_client_status_name(status),
                     loc_get_v02_qmi_status_name(ni_resp_ind.status));
            err = LOCATION_ERROR_GENERAL_FAILURE;
        }

        free((void *)passThroughData);
    }));
}