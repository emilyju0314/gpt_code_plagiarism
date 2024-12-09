void ewk_view_load_finished(Evas_Object* o, const Ewk_Frame_Load_Error* error)
{
    DBG("o=%p, error=%p", o, error);
    evas_object_smart_callback_call(o, "load,finished", (void*)error);
}