Eina_Bool ewk_view_select_none(Evas_Object* o)
{
    EWK_VIEW_SD_GET_OR_RETURN(o, sd, EINA_FALSE);
    EWK_VIEW_PRIV_GET_OR_RETURN(sd, priv, EINA_FALSE);
    return _ewk_view_editor_command(priv, "Unselect");
}