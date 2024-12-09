void FrameLoaderClientImpl::startDownload(const ResourceRequest& request)
{
    if (m_webFrame->client()) {
        WrappedResourceRequest webreq(request);
        m_webFrame->client()->loadURLExternally(
            m_webFrame, webreq, WebNavigationPolicyDownload);
    }
}