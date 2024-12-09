void ewk_view_bg_color_set(Evas_Object* o, int r, int g, int b, int a)
{
    EWK_VIEW_SD_GET_OR_RETURN(o, sd);
    EINA_SAFETY_ON_NULL_RETURN(sd->api);
    EINA_SAFETY_ON_NULL_RETURN(sd->api->bg_color_set);

    if (a < 0) {
        WRN("Alpha less than zero (%d).", a);
        a = 0;
    } else if (a > 255) {
        WRN("Alpha is larger than 255 (%d).", a);
        a = 255;
    }

#define CHECK_PREMUL_COLOR(c, a)                                        \
    if (c < 0) {                                                        \
        WRN("Color component "#c" is less than zero (%d).", c);         \
        c = 0;                                                          \
    } else if (c > a) {                                                 \
        WRN("Color component "#c" is greater than alpha (%d, alpha=%d).", \
            c, a);                                                      \
        c = a;                                                          \
    }
    CHECK_PREMUL_COLOR(r, a);
    CHECK_PREMUL_COLOR(g, a);
    CHECK_PREMUL_COLOR(b, a);
#undef CHECK_PREMUL_COLOR

    sd->bg_color.r = r;
    sd->bg_color.g = g;
    sd->bg_color.b = b;
    sd->bg_color.a = a;

    sd->api->bg_color_set(sd, r, g, b, a);

    WebCore::FrameView* view = sd->_priv->main_frame->view();
    if (view) {
        WebCore::Color color;

        if (!a)
            color = WebCore::Color(0, 0, 0, 0);
        else if (a == 255)
            color = WebCore::Color(r, g, b, a);
        else
            color = WebCore::Color(r * 255 / a, g * 255 / a, b * 255 / a, a);

        view->updateBackgroundRecursively(color, !a);
    }
}