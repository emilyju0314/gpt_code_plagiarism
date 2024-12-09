void ewk_view_scrollbars_visible_get(Evas_Object* o, Eina_Bool* visible)
{
    DBG("%s, o=%p", __func__, o);
    *visible = EINA_FALSE;
    evas_object_smart_callback_call(o, "scrollbars,visible,get", visible);
}