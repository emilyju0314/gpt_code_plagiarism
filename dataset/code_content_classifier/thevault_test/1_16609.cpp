Eina_Bool ewk_frame_text_matches_nth_pos_get(Evas_Object* o, size_t n, int* x, int* y)
{
    EWK_FRAME_SD_GET_OR_RETURN(o, sd, EINA_FALSE);
    EINA_SAFETY_ON_NULL_RETURN_VAL(sd->frame, EINA_FALSE);

    Vector<WebCore::IntRect> intRects = sd->frame->document()->markers()->renderedRectsForMarkers(WebCore::DocumentMarker::TextMatch);

    /* remove useless values */
    std::remove_if(intRects.begin(), intRects.end(), _ewk_frame_rect_is_negative_value);

    if (intRects.isEmpty() || n > intRects.size())
      return EINA_FALSE;

    std::sort(intRects.begin(), intRects.end(), _ewk_frame_rect_cmp_less_than);

    if (x)
      *x = intRects[n - 1].x();
    if (y)
      *y = intRects[n - 1].y();
    return EINA_TRUE;
}