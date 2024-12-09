gdouble webkit_download_get_elapsed_time(WebKitDownload* download)
{
    g_return_val_if_fail(WEBKIT_IS_DOWNLOAD(download), 0.0);

    WebKitDownloadPrivate* priv = download->priv;
    if (!priv->timer)
        return 0;

    return g_timer_elapsed(priv->timer, NULL);
}