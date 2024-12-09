Eina_Bool ewk_view_history_enable_get(const Evas_Object* o)
{
    EWK_VIEW_SD_GET_OR_RETURN(o, sd, EINA_FALSE);
    EWK_VIEW_PRIV_GET_OR_RETURN(sd, priv, EINA_FALSE);
    return static_cast<WebCore::BackForwardListImpl*>(priv->page->backForwardList())->enabled();
}