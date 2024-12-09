Eina_Bool
ewk_frame_scroll_set(Evas_Object* o, int x, int y)
{
    EWK_FRAME_SD_GET_OR_RETURN(o, sd, EINA_FALSE);
    EINA_SAFETY_ON_NULL_RETURN_VAL(sd->frame, EINA_FALSE);
    EINA_SAFETY_ON_NULL_RETURN_VAL(sd->frame->view(), EINA_FALSE);
    sd->frame->view()->setScrollPosition(WebCore::IntPoint(x, y));
    return EINA_TRUE;
}