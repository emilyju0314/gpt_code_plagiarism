void ewk_frame_load_finished(Evas_Object* o, const char* error_domain, int error_code, Eina_Bool is_cancellation, const char* error_description, const char* failing_url)
{
    Ewk_Frame_Load_Error buf, *error;
    if (!error_domain) {
        DBG("o=%p, success.", o);
        error = 0;
    } else {
        DBG("o=%p, error=%s (%d, cancellation=%hhu) \"%s\", url=%s",
            o, error_domain, error_code, is_cancellation,
            error_description, failing_url);

        buf.domain = error_domain;
        buf.code = error_code;
        buf.is_cancellation = is_cancellation;
        buf.description = error_description;
        buf.failing_url = failing_url;
        buf.frame = o;
        error = &buf;
    }
    evas_object_smart_callback_call(o, "load,finished", error);
    EWK_FRAME_SD_GET_OR_RETURN(o, sd);
    ewk_view_load_finished(sd->view, error);
}