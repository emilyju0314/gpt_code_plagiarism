static void locClientIndCb
(
 qmi_client_type                user_handle,
 unsigned int                   msg_id,
 void                           *ind_buf,
 unsigned int                   ind_buf_len,
 void                           *ind_cb_data
)
{
  locClientIndEnumT indType;
  size_t indSize = 0;
  qmi_client_error_type rc ;

  locClientCallbackDataType* pCallbackData =
      (locClientCallbackDataType *)ind_cb_data;

  LOC_LOGV("%s:%d]: Indication: msg_id=%d buf_len=%d pCallbackData = %p\n",
                __func__, __LINE__, (uint32_t)msg_id, ind_buf_len,
                pCallbackData);

  // check callback data
  if(NULL == pCallbackData ||(pCallbackData != pCallbackData->pMe))
  {
    LOC_LOGE("%s:%d]: invalid callback data", __func__, __LINE__);
    return;
  }

  // check user handle
  if(memcmp(&pCallbackData->userHandle, &user_handle, sizeof(user_handle)))
  {
    LOC_LOGE("%s:%d]: invalid user_handle got %p expected %p\n",
        __func__, __LINE__,
        user_handle, pCallbackData->userHandle);
    return;
  }
  // Get the indication size and type ( eventInd or respInd)
  if( true == locClientGetSizeAndTypeByIndId(msg_id, &indSize, &indType))
  {
    void *indBuffer = NULL;

    // decode the indication
    indBuffer = malloc(indSize);

    if(NULL == indBuffer)
    {
      LOC_LOGE("%s:%d]: memory allocation failed\n", __func__, __LINE__);
      return;
    }
    memset(indBuffer, 0, indSize);

    rc = QMI_NO_ERR;

    if (ind_buf_len > 0)
    {
        // decode the indication
        rc = qmi_client_message_decode(
            user_handle,
            QMI_IDL_INDICATION,
            msg_id,
            ind_buf,
            ind_buf_len,
            indBuffer,
            indSize);
    }

    if( rc == QMI_NO_ERR )
    {
      if(eventIndType == indType)
      {
        locClientEventIndUnionType eventIndUnion;

        /* copy the eventCallback function pointer from the callback
         * data to local variable. This is to protect against the race
         * condition between open/close and indication callback.
         */
        locClientEventIndCbType localEventCallback =
            pCallbackData->eventCallback;

        // dummy event
        eventIndUnion.pPositionReportEvent =
            (qmiLocEventPositionReportIndMsgT_v02 *)indBuffer;

        /* call the event callback
         * To avoid calling the eventCallback after locClientClose
         * is called, check pCallbackData->eventCallback again here
         */
        if((NULL != localEventCallback) &&
           (NULL != pCallbackData->eventCallback))
        {
          pthread_mutex_lock(&loc_shutdown_mutex);
          localEventCallback(
              (locClientHandleType)pCallbackData,
              msg_id,
              eventIndUnion,
              pCallbackData->pClientCookie);
          pthread_mutex_unlock(&loc_shutdown_mutex);
        }
      }
      else if(respIndType == indType)
      {
        locClientRespIndUnionType respIndUnion;

        /* copy the respCallback function pointer from the callback
         * data to local variable. This is to protect against the race
         * condition between open/close and indication callback.
         */
        locClientRespIndCbType localRespCallback =
            pCallbackData->respCallback;

        // dummy to suppress compiler warnings
        respIndUnion.pDeleteAssistDataInd =
            (qmiLocDeleteAssistDataIndMsgT_v02 *)indBuffer;

        /* call the response callback
         * To avoid calling the respCallback after locClientClose
         * is called, check pCallbackData->respCallback again here
         */
        if((NULL != localRespCallback) &&
           (NULL != pCallbackData->respCallback))
        {
          pthread_mutex_lock(&loc_shutdown_mutex);
          localRespCallback(
              (locClientHandleType)pCallbackData,
              msg_id,
              respIndUnion,
              indSize,
              pCallbackData->pClientCookie);
          pthread_mutex_unlock(&loc_shutdown_mutex);
        }
      }
    }
    else
    {
      LOC_LOGE("%s:%d]: Error decoding indication %d\n",
                    __func__, __LINE__, rc);
    }
    if(indBuffer)
    {
      free (indBuffer);
    }
  }
  else // Id not found
  {
    LOC_LOGE("%s:%d]: Error indication not found %d\n",
                  __func__, __LINE__,(uint32_t)msg_id);
  }
  return;
}