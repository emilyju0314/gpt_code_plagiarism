void ewk_view_download_request(Evas_Object* o, Ewk_Download* download)
{
    DBG("view=%p", o);
    evas_object_smart_callback_call(o, "download,request", download);
}