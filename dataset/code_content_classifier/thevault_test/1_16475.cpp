void ewk_view_popup_selected_set(Evas_Object* o, int index)
{
    INF("o=%p", o);
    EWK_VIEW_SD_GET_OR_RETURN(o, sd);
    EWK_VIEW_PRIV_GET_OR_RETURN(sd, priv);
    EINA_SAFETY_ON_NULL_RETURN(priv->popup.menu_client);

    priv->popup.menu_client->valueChanged(index);
}