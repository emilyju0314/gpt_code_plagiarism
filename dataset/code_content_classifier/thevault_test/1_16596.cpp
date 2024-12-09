void ewk_frame_theme_set(Evas_Object* o, const char* path)
{
    EWK_FRAME_SD_GET_OR_RETURN(o, sd);
    if (!eina_stringshare_replace(&sd->theme, path))
        return;
    if (sd->frame && sd->frame->view()) {
        sd->frame->view()->setEdjeTheme(WTF::String(path));
        sd->frame->page()->theme()->themeChanged();
    }
}