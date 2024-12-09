void ewk_view_ready(Evas_Object* o)
{
    DBG("o=%p", o);
    evas_object_smart_callback_call(o, "ready", 0);
}