void ewk_view_title_set(Evas_Object* o, const char* title)
{
    DBG("o=%p, title=%s", o, title ? title : "(null)");
    evas_object_smart_callback_call(o, "title,changed", (void*)title);
}