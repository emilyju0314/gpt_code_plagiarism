Eina_Bool ewk_view_paint_contents(Ewk_View_Private_Data* priv, cairo_t* cr, const Eina_Rectangle* area)
{
    EINA_SAFETY_ON_NULL_RETURN_VAL(priv, EINA_FALSE);
    EINA_SAFETY_ON_NULL_RETURN_VAL(cr, EINA_FALSE);
    EINA_SAFETY_ON_NULL_RETURN_VAL(area, EINA_FALSE);
    WebCore::FrameView* view = priv->main_frame->view();
    EINA_SAFETY_ON_NULL_RETURN_VAL(view, EINA_FALSE);

    WebCore::GraphicsContext gc(cr);
    WebCore::IntRect rect(area->x, area->y, area->w, area->h);

    cairo_save(cr);
    gc.save();
    gc.clip(rect);
    if (view->isTransparent())
        gc.clearRect(rect);
    view->paintContents(&gc,  rect);
    gc.restore();
    cairo_restore(cr);

    return EINA_TRUE;
}