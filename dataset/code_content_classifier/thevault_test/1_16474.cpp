Eina_Bool ewk_view_popup_destroy(Evas_Object* o)
{
    INF("o=%p", o);
    EWK_VIEW_SD_GET_OR_RETURN(o, sd, EINA_FALSE);
    EWK_VIEW_PRIV_GET_OR_RETURN(sd, priv, EINA_FALSE);

    if (!priv->popup.menu_client)
        return EINA_FALSE;

    evas_object_smart_callback_call(o, "popup,willdelete", &priv->popup.menu);

    void* itemv;
    EINA_LIST_FREE(priv->popup.menu.items, itemv) {
        Ewk_Menu_Item* item = (Ewk_Menu_Item*)itemv;
        eina_stringshare_del(item->text);
        free(item);
    }
    priv->popup.menu_client->popupDidHide();
    priv->popup.menu_client = 0;

    return EINA_TRUE;
}