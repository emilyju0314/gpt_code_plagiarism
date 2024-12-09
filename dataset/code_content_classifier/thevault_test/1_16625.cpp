void ewk_frame_contents_size_changed(Evas_Object* o, Evas_Coord w, Evas_Coord h)
{
    DBG("o=%p: %dx%d", o, w, h);
    EWK_FRAME_SD_GET_OR_RETURN(o, sd);
    if (sd->contents_size.w == w && sd->contents_size.h == h)
        return;
    sd->contents_size.w = w;
    sd->contents_size.h = h;
    // TODO: update something else internally?

    Evas_Coord size[2] = {w, h};
    evas_object_smart_callback_call(o, "contents,size,changed", size);
}