void FrameLoaderClientImpl::assignIdentifierToInitialRequest(
    unsigned long identifier, DocumentLoader* loader,
    const ResourceRequest& request)
{
    if (m_webFrame->client()) {
        WrappedResourceRequest webreq(request);
        m_webFrame->client()->assignIdentifierToRequest(
            m_webFrame, identifier, webreq);
    }
}