void webkit_download_cancel(WebKitDownload* download)
{
    g_return_if_fail(WEBKIT_IS_DOWNLOAD(download));

    WebKitDownloadPrivate* priv = download->priv;

    // Cancel may be called even if start was not called, so we need
    // to make sure timer is non-NULL.
    if (priv->timer)
        g_timer_stop(priv->timer);

    if (priv->resourceHandle)
        priv->resourceHandle->cancel();

    webkit_download_set_status(download, WEBKIT_DOWNLOAD_STATUS_CANCELLED);

    gboolean handled;
    g_signal_emit_by_name(download, "error", 0, WEBKIT_DOWNLOAD_ERROR_CANCELLED_BY_USER, _("User cancelled the download"), &handled);
}