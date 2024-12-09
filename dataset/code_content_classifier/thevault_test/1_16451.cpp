void ewk_view_paint_context_free(Ewk_View_Paint_Context* ctxt)
{
    EINA_SAFETY_ON_NULL_RETURN(ctxt);
    delete ctxt->gc;
    cairo_destroy(ctxt->cr);
    free(ctxt);
}