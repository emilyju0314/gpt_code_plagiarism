void ewk_view_paint_context_save(Ewk_View_Paint_Context* ctxt)
{
    EINA_SAFETY_ON_NULL_RETURN(ctxt);
    cairo_save(ctxt->cr);
    ctxt->gc->save();
}