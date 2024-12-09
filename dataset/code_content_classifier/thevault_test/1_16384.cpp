void FrameLoaderClientImpl::dispatchDidCancelClientRedirect()
{
    // No longer expecting a client redirect.
    if (m_webFrame->client()) {
        m_expectedClientRedirectSrc = KURL();
        m_expectedClientRedirectDest = KURL();
        m_webFrame->client()->didCancelClientRedirect(m_webFrame);
    }

    // No need to clear the redirect chain, since that data source has already
    // been deleted by the time this function is called.
}