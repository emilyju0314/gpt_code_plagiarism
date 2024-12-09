Ewk_View_Paint_Context* ewk_view_paint_context_new(Ewk_View_Private_Data* priv, cairo_t* cr)
{
    EINA_SAFETY_ON_NULL_RETURN_VAL(priv, 0);
    EINA_SAFETY_ON_NULL_RETURN_VAL(cr, 0);
    EINA_SAFETY_ON_NULL_RETURN_VAL(priv->main_frame, 0);
    WebCore::FrameView* view = priv->main_frame->view();
    EINA_SAFETY_ON_NULL_RETURN_VAL(view, 0);
    Ewk_View_Paint_Context* ctxt = (Ewk_View_Paint_Context*)malloc(sizeof(*ctxt));
    EINA_SAFETY_ON_NULL_RETURN_VAL(ctxt, 0);

    ctxt->gc = new WebCore::GraphicsContext(cr);
    if (!ctxt->gc) {
        free(ctxt);
        return 0;
    }
    ctxt->view = view;
    ctxt->cr = cairo_reference(cr);
    return ctxt;
}