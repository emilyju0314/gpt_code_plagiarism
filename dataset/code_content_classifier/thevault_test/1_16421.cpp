char* ewk_view_selection_get(const Evas_Object* o)
{
    EWK_VIEW_SD_GET_OR_RETURN(o, sd, 0);
    EWK_VIEW_PRIV_GET_OR_RETURN(sd, priv, 0);
    CString s = priv->page->focusController()->focusedOrMainFrame()->editor()->selectedText().utf8();
    if (s.isNull())
        return 0;
    return strdup(s.data());
}