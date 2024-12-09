guint64 webkit_download_get_total_size(WebKitDownload* download)
{
    g_return_val_if_fail(WEBKIT_IS_DOWNLOAD(download), 0);

    WebKitDownloadPrivate* priv = download->priv;
    SoupMessage* message = priv->networkResponse ? webkit_network_response_get_message(priv->networkResponse) : NULL;

    if (!message)
        return 0;

    return MAX(priv->currentSize, static_cast<guint64>(soup_message_headers_get_content_length(message->response_headers)));
}