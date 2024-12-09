unsigned int ewk_view_text_matches_mark(Evas_Object* o, const char* string, Eina_Bool case_sensitive, Eina_Bool highlight, unsigned int limit)
{
    EWK_VIEW_SD_GET_OR_RETURN(o, sd, 0);
    EWK_VIEW_PRIV_GET_OR_RETURN(sd, priv, 0);
    EINA_SAFETY_ON_NULL_RETURN_VAL(string, 0);
    WTF::TextCaseSensitivity sensitive;

    if (case_sensitive)
        sensitive = WTF::TextCaseSensitive;
    else
        sensitive = WTF::TextCaseInsensitive;

    return priv->page->markAllMatchesForText(String::fromUTF8(string), sensitive, highlight, limit);
}