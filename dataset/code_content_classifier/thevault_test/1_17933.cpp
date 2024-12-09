auto static inline
query_name_window(Display *dpy, Window start) noexcept -> Window
{
        Window w;
        w = XmuClientWindow(dpy, start);
        return w;
}