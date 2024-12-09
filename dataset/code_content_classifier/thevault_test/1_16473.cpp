void ewk_view_popup_new(Evas_Object* o, WebCore::PopupMenuClient* client, int selected, const WebCore::IntRect& rect)
{
    INF("o=%p", o);
    EWK_VIEW_SD_GET_OR_RETURN(o, sd);
    EWK_VIEW_PRIV_GET_OR_RETURN(sd, priv);

    if (priv->popup.menu_client)
        ewk_view_popup_destroy(o);

    priv->popup.menu_client = client;

    // populate items
    const int size = client->listSize();
    for (int i = 0; i < size; ++i) {
        Ewk_Menu_Item* item = (Ewk_Menu_Item*) malloc(sizeof(*item));
        if (client->itemIsSeparator(i))
            item->type = EWK_MENU_SEPARATOR;
        else if (client->itemIsLabel(i))
            item->type = EWK_MENU_GROUP;
        else
            item->type = EWK_MENU_OPTION;
        item->text = eina_stringshare_add(client->itemText(i).utf8().data());

        priv->popup.menu.items = eina_list_append(priv->popup.menu.items, item);
    }

    priv->popup.menu.x = rect.x();
    priv->popup.menu.y = rect.y();
    priv->popup.menu.width = rect.width();
    priv->popup.menu.height = rect.height();
    evas_object_smart_callback_call(o, "popup,create", &priv->popup.menu);
}