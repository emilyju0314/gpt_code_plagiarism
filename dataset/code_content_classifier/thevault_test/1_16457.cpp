void ewk_view_paint_context_scale(Ewk_View_Paint_Context* ctxt, float scale_x, float scale_y)
{
    EINA_SAFETY_ON_NULL_RETURN(ctxt);

    ctxt->gc->scale(WebCore::FloatSize(scale_x, scale_y));
}