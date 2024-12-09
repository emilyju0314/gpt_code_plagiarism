void FrameLoaderClientImpl::committedLoad(DocumentLoader* loader, const char* data, int length)
{
    if (!m_pluginWidget.get()) {
        if (m_webFrame->client()) {
            bool preventDefault = false;
            m_webFrame->client()->didReceiveDocumentData(m_webFrame, data, length, preventDefault);
            if (!preventDefault)
                m_webFrame->commitDocumentData(data, length);
        }
    }

    // If we are sending data to MediaDocument, we should stop here
    // and cancel the request.
    if (m_webFrame->frame()->document()->isMediaDocument())
        loader->cancelMainResourceLoad(pluginWillHandleLoadError(loader->response()));

    // The plugin widget could have been created in the m_webFrame->DidReceiveData
    // function.
    if (m_pluginWidget.get()) {
        if (!m_sentInitialResponseToPlugin) {
            m_sentInitialResponseToPlugin = true;
            m_pluginWidget->didReceiveResponse(
                m_webFrame->frame()->loader()->activeDocumentLoader()->response());
        }

        // It's possible that the above call removed the pointer to the plugin, so
        // check before calling it.
        if (m_pluginWidget.get())
            m_pluginWidget->didReceiveData(data, length);
    }
}