void ewk_view_paint_context_translate(Ewk_View_Paint_Context* ctxt, float x, float y)
{
    EINA_SAFETY_ON_NULL_RETURN(ctxt);

    ctxt->gc->translate(x, y);
}