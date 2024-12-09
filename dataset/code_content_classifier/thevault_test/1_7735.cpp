void LocApiV02 :: reportNiRequest(
    const qmiLocEventNiNotifyVerifyReqIndMsgT_v02 *ni_req_ptr)
{
    GnssNiNotification notif = {};
    notif.messageEncoding = GNSS_NI_ENCODING_TYPE_NONE ;
    notif.requestorEncoding = GNSS_NI_ENCODING_TYPE_NONE;
    notif.timeoutResponse = GNSS_NI_RESPONSE_NO_RESPONSE;
    notif.timeout = LOC_NI_NO_RESPONSE_TIME;

    /* Handle Vx request */
    if (1 == ni_req_ptr->NiVxInd_valid) {
        const qmiLocNiVxNotifyVerifyStructT_v02 *vx_req = &(ni_req_ptr->NiVxInd);

        notif.type = GNSS_NI_TYPE_VOICE;

        // Requestor ID, the requestor id recieved is NULL terminated
        hexcode(notif.requestor, sizeof notif.requestor,
                (char *)vx_req->requestorId, vx_req->requestorId_len );
    }

    /* Handle UMTS CP request*/
    else if (1 == ni_req_ptr->NiUmtsCpInd_valid) {
        const qmiLocNiUmtsCpNotifyVerifyStructT_v02 *umts_cp_req =
            &ni_req_ptr->NiUmtsCpInd;

        notif.type = GNSS_NI_TYPE_CONTROL_PLANE;

        /* notificationText should always be a NULL terminated string */
        hexcode(notif.message, sizeof notif.message,
                (char *)umts_cp_req->notificationText,
                umts_cp_req->notificationText_len);

        /* Store requestor ID */
        hexcode(notif.requestor, sizeof(notif.requestor),
                (char *)umts_cp_req->requestorId.codedString,
                umts_cp_req->requestorId.codedString_len);

        /* convert encodings */
        notif.messageEncoding = convertNiEncoding(umts_cp_req->dataCodingScheme);

        notif.requestorEncoding =
            convertNiEncoding(umts_cp_req->requestorId.dataCodingScheme);

        /* LCS address (using extras field) */
        if (0 != umts_cp_req->clientAddress_len) {
            char lcs_addr[32]; // Decoded LCS address for UMTS CP NI

            // Copy LCS Address into notif.extras in the format: Address = 012345
            strlcat(notif.extras, LOC_NI_NOTIF_KEY_ADDRESS, sizeof (notif.extras));
            strlcat(notif.extras, " = ", sizeof notif.extras);
            int addr_len = 0;
            const char *address_source = NULL;
            address_source = (char *)umts_cp_req->clientAddress;
            // client Address is always NULL terminated
            addr_len = decodeAddress(lcs_addr, sizeof(lcs_addr), address_source,
                                     umts_cp_req->clientAddress_len);

            // The address is ASCII string
            if (addr_len) {
                strlcat(notif.extras, lcs_addr, sizeof notif.extras);
            }
        }
    } else if (1 == ni_req_ptr->NiSuplInd_valid) {
        const qmiLocNiSuplNotifyVerifyStructT_v02 *supl_req =
            &ni_req_ptr->NiSuplInd;

        notif.type = GNSS_NI_TYPE_SUPL;

        // Client name
        if (supl_req->valid_flags & QMI_LOC_SUPL_CLIENT_NAME_MASK_V02) {
            hexcode(notif.message, sizeof(notif.message),
                    (char *)supl_req->clientName.formattedString,
                    supl_req->clientName.formattedString_len);
            LOC_LOGv("SUPL NI: client_name: %s \n", notif.message);
        } else {
            LOC_LOGv("SUPL NI: client_name not present.");
        }

        // Requestor ID
        if (supl_req->valid_flags & QMI_LOC_SUPL_REQUESTOR_ID_MASK_V02) {
            hexcode(notif.requestor, sizeof notif.requestor,
                    (char*)supl_req->requestorId.formattedString,
                    supl_req->requestorId.formattedString_len);

            LOC_LOGv("SUPL NI: requestor: %s", notif.requestor);
        } else {
            LOC_LOGv("SUPL NI: requestor not present.");
        }

        // Encoding type
        if (supl_req->valid_flags & QMI_LOC_SUPL_DATA_CODING_SCHEME_MASK_V02) {
            notif.messageEncoding = convertNiEncoding(supl_req->dataCodingScheme);
            notif.requestorEncoding = convertNiEncoding(supl_req->dataCodingScheme);
        } else {
            notif.messageEncoding = notif.requestorEncoding = GNSS_NI_ENCODING_TYPE_NONE;
        }

        // ES SUPL
        if (1 == ni_req_ptr->suplEmergencyNotification_valid) {
            const qmiLocEmergencyNotificationStructT_v02 *supl_emergency_request =
                &ni_req_ptr->suplEmergencyNotification;

            notif.type = GNSS_NI_TYPE_EMERGENCY_SUPL;
        }
    } //ni_req_ptr->NiSuplInd_valid == 1
    else {
        LOC_LOGe("unknown request event");
        return;
    }

    // Set default_response & notify_flags
    convertNiNotifyVerifyType(&notif, ni_req_ptr->notificationType);

    qmiLocEventNiNotifyVerifyReqIndMsgT_v02 *ni_req_copy_ptr =
        (qmiLocEventNiNotifyVerifyReqIndMsgT_v02 *)malloc(sizeof(*ni_req_copy_ptr));

    LocInEmergency emergencyState = ni_req_ptr->isInEmergencySession_valid ?
            (ni_req_ptr->isInEmergencySession ? LOC_IN_EMERGENCY_SET : LOC_IN_EMERGENCY_NOT_SET) :
            LOC_IN_EMERGENCY_UNKNOWN;
    if (NULL != ni_req_copy_ptr) {
        memcpy(ni_req_copy_ptr, ni_req_ptr, sizeof(*ni_req_copy_ptr));
        requestNiNotify(notif, (const void*)ni_req_copy_ptr, emergencyState);
    } else {
        LOC_LOGe("Error copying NI request");
    }
}