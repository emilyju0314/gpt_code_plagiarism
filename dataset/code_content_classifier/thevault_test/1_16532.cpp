void webkit_download_set_destination_uri(WebKitDownload* download, const gchar* destination_uri)
{
    g_return_if_fail(WEBKIT_IS_DOWNLOAD(download));
    g_return_if_fail(destination_uri);

    WebKitDownloadPrivate* priv = download->priv;
    if (priv->destinationURI && !strcmp(priv->destinationURI, destination_uri))
        return;

    if (priv->status != WEBKIT_DOWNLOAD_STATUS_CREATED && priv->status != WEBKIT_DOWNLOAD_STATUS_CANCELLED) {
        ASSERT(priv->destinationURI);

        gboolean downloading = priv->outputStream != NULL;
        if (downloading)
            webkit_download_close_stream(download);

        GFile* src = g_file_new_for_uri(priv->destinationURI);
        GFile* dest = g_file_new_for_uri(destination_uri);
        GError* error = NULL;

        g_file_move(src, dest, G_FILE_COPY_BACKUP, NULL, NULL, NULL, &error);

        g_object_unref(src);
        g_object_unref(dest);

        g_free(priv->destinationURI);
        priv->destinationURI = g_strdup(destination_uri);

        if (error) {
            gboolean handled;
            g_signal_emit_by_name(download, "error", 0, WEBKIT_DOWNLOAD_ERROR_DESTINATION, error->message, &handled);
            g_error_free(error);
            return;
        }

        if (downloading) {
            if (!webkit_download_open_stream_for_uri(download, destination_uri, TRUE)) {
                webkit_download_cancel(download);
                return;
            }
        }
    } else {
        g_free(priv->destinationURI);
        priv->destinationURI = g_strdup(destination_uri);
    }

    // Only notify change if everything went fine.
    g_object_notify(G_OBJECT(download), "destination-uri");
}