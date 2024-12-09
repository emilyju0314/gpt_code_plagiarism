void ewk_view_paint_context_paint_contents(Ewk_View_Paint_Context* ctxt, const Eina_Rectangle* area)
{
    EINA_SAFETY_ON_NULL_RETURN(ctxt);
    EINA_SAFETY_ON_NULL_RETURN(area);

    WebCore::IntRect rect(area->x, area->y, area->w, area->h);

    if (ctxt->view->isTransparent())
        ctxt->gc->clearRect(rect);

    ctxt->view->paintContents(ctxt->gc, rect);
}