int
event_handler(TSCont cont, TSEvent event, void *edata)
{
  TSHttpTxn txnp       = static_cast<TSHttpTxn>(edata);
  S3Config *s3         = static_cast<S3Config *>(TSContDataGet(cont));
  TSEvent enable_event = TS_EVENT_HTTP_CONTINUE;

  {
    S3Request request(txnp);
    TSHttpStatus status = TS_HTTP_STATUS_INTERNAL_SERVER_ERROR;

    switch (event) {
    case TS_EVENT_HTTP_SEND_REQUEST_HDR:
      if (request.initialize()) {
        std::shared_lock lock(s3->reload_mutex);
        status = request.authorize(s3);
      }

      if (TS_HTTP_STATUS_OK == status) {
        TSDebug(PLUGIN_NAME, "Successfully signed the AWS S3 URL");
      } else {
        TSDebug(PLUGIN_NAME, "Failed to sign the AWS S3 URL, status = %d", status);
        TSHttpTxnStatusSet(txnp, status);
        enable_event = TS_EVENT_HTTP_ERROR;
      }
      break;
    default:
      TSError("[%s] Unknown event for this plugin", PLUGIN_NAME);
      TSDebug(PLUGIN_NAME, "unknown event for this plugin");
      break;
    }
    // Most get S3Request out of scope in case the later plugins invalidate the TSAPI
    // objects it references.  Some cases were causing asserts from the destructor
  }

  TSHttpTxnReenable(txnp, enable_event);
  return 0;
}