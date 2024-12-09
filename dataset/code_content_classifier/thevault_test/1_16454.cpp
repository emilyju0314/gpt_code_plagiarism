void ewk_view_paint_context_clip(Ewk_View_Paint_Context* ctxt, const Eina_Rectangle* area)
{
    EINA_SAFETY_ON_NULL_RETURN(ctxt);
    EINA_SAFETY_ON_NULL_RETURN(area);
    ctxt->gc->clip(WebCore::IntRect(area->x, area->y, area->w, area->h));
}