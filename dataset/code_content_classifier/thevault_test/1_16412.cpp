void ewk_view_fixed_layout_size_set(Evas_Object* o, Evas_Coord w, Evas_Coord h)
{
    EWK_VIEW_SD_GET_OR_RETURN(o, sd);
    EWK_VIEW_PRIV_GET_OR_RETURN(sd, priv);

    WebCore::FrameView* view = sd->_priv->main_frame->view();
    if (w <= 0 && h <= 0) {
        if (!priv->fixed_layout.use)
            return;
        priv->fixed_layout.w = 0;
        priv->fixed_layout.h = 0;
        priv->fixed_layout.use = EINA_FALSE;
    } else {
        if (priv->fixed_layout.use
            && priv->fixed_layout.w == w && priv->fixed_layout.h == h)
            return;
        priv->fixed_layout.w = w;
        priv->fixed_layout.h = h;
        priv->fixed_layout.use = EINA_TRUE;

        if (view)
            view->setFixedLayoutSize(WebCore::IntSize(w, h));
    }

    if (!view)
        return;
    view->setUseFixedLayout(priv->fixed_layout.use);
    view->forceLayout();
}