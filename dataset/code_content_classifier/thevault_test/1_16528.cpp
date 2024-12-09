void webkit_download_start(WebKitDownload* download)
{
    g_return_if_fail(WEBKIT_IS_DOWNLOAD(download));

    WebKitDownloadPrivate* priv = download->priv;
    g_return_if_fail(priv->destinationURI);
    g_return_if_fail(priv->status == WEBKIT_DOWNLOAD_STATUS_CREATED);
    g_return_if_fail(priv->timer == NULL);

    // For GTK, when downloading a file NetworkingContext is null
    if (!priv->resourceHandle)
        priv->resourceHandle = ResourceHandle::create(/* Null NetworkingContext */ NULL, core(priv->networkRequest), priv->downloadClient, false, false);
    else {
        priv->resourceHandle->setClient(priv->downloadClient);

        ResourceHandleInternal* d = priv->resourceHandle->getInternal();
        if (d->m_soupMessage)
            soup_session_unpause_message(webkit_get_default_session(), d->m_soupMessage.get());
    }

    priv->timer = g_timer_new();
    webkit_download_open_stream_for_uri(download, priv->destinationURI);
}