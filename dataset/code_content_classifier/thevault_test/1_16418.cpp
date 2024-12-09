void ewk_view_bg_color_get(const Evas_Object* o, int* r, int* g, int* b, int* a)
{
    if (r)
        *r = 0;
    if (g)
        *g = 0;
    if (b)
        *b = 0;
    if (a)
        *a = 0;
    EWK_VIEW_SD_GET_OR_RETURN(o, sd);
    if (r)
        *r = sd->bg_color.r;
    if (g)
        *g = sd->bg_color.g;
    if (b)
        *b = sd->bg_color.b;
    if (a)
        *a = sd->bg_color.a;
}