const gchar* webkit_download_get_suggested_filename(WebKitDownload* download)
{
    g_return_val_if_fail(WEBKIT_IS_DOWNLOAD(download), NULL);

    WebKitDownloadPrivate* priv = download->priv;
    if (priv->suggestedFilename)
        return priv->suggestedFilename;

    KURL url = KURL(KURL(), webkit_network_request_get_uri(priv->networkRequest));
    url.setQuery(String());
    url.removeFragmentIdentifier();
    priv->suggestedFilename = g_strdup(decodeURLEscapeSequences(url.lastPathComponent()).utf8().data());
    return priv->suggestedFilename;
}