TSRemapStatus
TSRemapDoRemap(void *ih, TSHttpTxn txnp, TSRemapRequestInfo * /* rri */)
{
  S3Config *s3 = static_cast<S3Config *>(ih);

  if (s3) {
    TSAssert(s3->valid());
    // Now schedule the continuation to update the URL when going to origin.
    // Note that in most cases, this is a No-Op, assuming you have reasonable
    // cache hit ratio. However, the scheduling is next to free (very cheap).
    // Another option would be to use a single global hook, and pass the "s3"
    // configs via a TXN argument.
    s3->schedule(txnp);
  } else {
    TSDebug(PLUGIN_NAME, "Remap context is invalid");
    TSError("[%s] No remap context available, check code / config", PLUGIN_NAME);
    TSHttpTxnStatusSet(txnp, TS_HTTP_STATUS_INTERNAL_SERVER_ERROR);
  }

  // This plugin actually doesn't do anything with remapping. Ever.
  return TSREMAP_NO_REMAP;
}