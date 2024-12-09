Eina_Bool
ewk_frame_scroll_size_get(const Evas_Object* o, int* w, int* h)
{
    if (w)
        *w = 0;
    if (h)
        *h = 0;
    EWK_FRAME_SD_GET_OR_RETURN(o, sd, EINA_FALSE);
    EINA_SAFETY_ON_NULL_RETURN_VAL(sd->frame, EINA_FALSE);
    EINA_SAFETY_ON_NULL_RETURN_VAL(sd->frame->view(), EINA_FALSE);
    WebCore::IntPoint point = sd->frame->view()->maximumScrollPosition();
    if (w)
        *w = point.x();
    if (h)
        *h = point.y();
    return EINA_TRUE;
}