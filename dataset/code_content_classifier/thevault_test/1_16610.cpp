Eina_Bool ewk_frame_navigate(Evas_Object* o, int steps)
{
    EWK_FRAME_SD_GET_OR_RETURN(o, sd, EINA_FALSE);
    EINA_SAFETY_ON_NULL_RETURN_VAL(sd->frame, EINA_FALSE);
    WebCore::Page* page = sd->frame->page();
    if (!page->canGoBackOrForward(steps))
        return EINA_FALSE;
    page->goBackOrForward(steps);
    return EINA_TRUE;
}