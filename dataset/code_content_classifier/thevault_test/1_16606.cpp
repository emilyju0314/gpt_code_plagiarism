Eina_Bool ewk_frame_select_none(Evas_Object* o)
{
    EWK_FRAME_SD_GET_OR_RETURN(o, sd, EINA_FALSE);
    EINA_SAFETY_ON_NULL_RETURN_VAL(sd->frame, EINA_FALSE);
    return _ewk_frame_editor_command(sd, "Unselect");
}