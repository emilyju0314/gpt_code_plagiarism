void ewk_settings_proxy_uri_set(const char* proxy)
{
#if USE(SOUP)
    SoupSession* session = WebCore::ResourceHandle::defaultSession();

    if (!proxy) {
        ERR("no proxy uri. remove proxy feature in soup.");
        soup_session_remove_feature_by_type(session, SOUP_TYPE_PROXY_RESOLVER);
        return;
    }

    SoupURI* uri = soup_uri_new(proxy);
    EINA_SAFETY_ON_NULL_RETURN(uri);

    g_object_set(session, SOUP_SESSION_PROXY_URI, uri, NULL);
    soup_uri_free(uri);
#elif USE(CURL)
    EINA_SAFETY_ON_TRUE_RETURN(1);
#endif
}