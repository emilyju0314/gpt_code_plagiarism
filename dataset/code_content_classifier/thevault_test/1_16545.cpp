const char* ewk_settings_proxy_uri_get(void)
{
#if USE(SOUP)
    SoupURI* uri;
    SoupSession* session = WebCore::ResourceHandle::defaultSession();
    g_object_get(session, SOUP_SESSION_PROXY_URI, &uri, NULL);

    if (!uri) {
        ERR("no proxy uri");
        return 0;
    }

    WTF::String proxy = soup_uri_to_string(uri, EINA_FALSE);
    return eina_stringshare_add(proxy.utf8().data());
#elif USE(CURL)
    EINA_SAFETY_ON_TRUE_RETURN_VAL(1, 0);
#endif
}