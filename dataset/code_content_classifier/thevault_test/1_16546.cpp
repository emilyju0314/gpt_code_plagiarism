const char* ewk_settings_default_user_agent_get(void)
{
    WTF::String ua_version = makeString(String::number(WEBKIT_USER_AGENT_MAJOR_VERSION), '.', String::number(WEBKIT_USER_AGENT_MINOR_VERSION), '+');
    WTF::String static_ua = makeString("Mozilla/5.0 (", _ewk_settings_webkit_platform_get(), "; ", _ewk_settings_webkit_os_version_get(), ") AppleWebKit/", ua_version) + makeString(" (KHTML, like Gecko) Version/5.0 Safari/", ua_version);

    return eina_stringshare_add(static_ua.utf8().data());
}