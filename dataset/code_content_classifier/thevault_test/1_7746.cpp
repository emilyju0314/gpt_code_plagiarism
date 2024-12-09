static void locClientErrorCb
(
  qmi_client_type user_handle,
  qmi_client_error_type error,
  void *err_cb_data
)
{
  (void)user_handle;

  locClientCallbackDataType* pCallbackData =
        (locClientCallbackDataType *)err_cb_data;
  locClientErrorCbType localErrorCallback = NULL;

  /* copy the errorCallback function pointer from the callback
   * data to local variable. This is to protect against the race
   * condition between open/close and error callback.
   */
  if(NULL != pCallbackData)
  {
    localErrorCallback = pCallbackData->errorCallback;
  }

  LOC_LOGD("%s:%d]: Service Error %d received, pCallbackData = %p\n",
      __func__, __LINE__, error, err_cb_data);

  /* call the error callback
   * To avoid calling the errorCallback after locClientClose
   * is called, check pCallbackData->errorCallback again here
   */

  if( (NULL != pCallbackData) &&
      (NULL != localErrorCallback) &&
      (NULL != pCallbackData->errorCallback) &&
      (pCallbackData == pCallbackData->pMe)  )
  {
    pthread_mutex_lock(&loc_shutdown_mutex);
    //invoke the error callback for the corresponding client
    localErrorCallback(
        (locClientHandleType)pCallbackData,
        convertQmiErrorToLocError(error),
        pCallbackData->pClientCookie);
    pthread_mutex_unlock(&loc_shutdown_mutex);
  }
}