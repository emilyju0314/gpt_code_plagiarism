static inline cairo_surface_t* copySurface(cairo_surface_t* surface)
{
    cairo_format_t format = cairo_image_surface_get_format(surface);
    int width = cairo_image_surface_get_width(surface);
    int height = cairo_image_surface_get_height(surface);
    cairo_surface_t* newsurface = cairo_image_surface_create(format, width, height);

    cairo_t* cr = cairo_create(newsurface);
    cairo_set_source_surface(cr, surface, 0, 0);
    cairo_set_operator(cr, CAIRO_OPERATOR_SOURCE);
    cairo_paint(cr);
    cairo_destroy(cr);

    return newsurface;
}