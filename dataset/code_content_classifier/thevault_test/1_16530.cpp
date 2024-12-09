const gchar* webkit_download_get_uri(WebKitDownload* download)
{
    g_return_val_if_fail(WEBKIT_IS_DOWNLOAD(download), NULL);

    WebKitDownloadPrivate* priv = download->priv;
    return webkit_network_request_get_uri(priv->networkRequest);
}