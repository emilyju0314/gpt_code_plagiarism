void ewk_view_menubar_visible_get(Evas_Object* o, Eina_Bool* visible)
{
    DBG("%s, o=%p", __func__, o);
    *visible = EINA_FALSE;
    evas_object_smart_callback_call(o, "menubar,visible,get", visible);
}