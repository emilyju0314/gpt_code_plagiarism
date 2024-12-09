Eina_Bool ewk_view_text_search(const Evas_Object* o, const char* string, Eina_Bool case_sensitive, Eina_Bool forward, Eina_Bool wrap)
{
    EWK_VIEW_SD_GET_OR_RETURN(o, sd, EINA_FALSE);
    EWK_VIEW_PRIV_GET_OR_RETURN(sd, priv, EINA_FALSE);
    EINA_SAFETY_ON_NULL_RETURN_VAL(string, EINA_FALSE);
    WTF::TextCaseSensitivity sensitive;
    WebCore::FindDirection direction;

    if (case_sensitive)
        sensitive = WTF::TextCaseSensitive;
    else
        sensitive = WTF::TextCaseInsensitive;

    if (forward)
        direction = WebCore::FindDirectionForward;
    else
        direction = WebCore::FindDirectionBackward;

    return priv->page->findString(String::fromUTF8(string), sensitive, direction, wrap);
}