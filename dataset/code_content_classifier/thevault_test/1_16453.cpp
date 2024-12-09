void ewk_view_paint_context_restore(Ewk_View_Paint_Context* ctxt)
{
    EINA_SAFETY_ON_NULL_RETURN(ctxt);
    ctxt->gc->restore();
    cairo_restore(ctxt->cr);
}