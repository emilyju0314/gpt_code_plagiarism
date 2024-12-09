Eina_Bool ewk_frame_contents_alternate_set(Evas_Object* o, const char* contents, size_t contents_size, const char* mime_type, const char* encoding, const char* base_uri, const char* unreachable_uri)
{
    EWK_FRAME_SD_GET_OR_RETURN(o, sd, EINA_FALSE);
    EINA_SAFETY_ON_FALSE_RETURN_VAL(sd->frame, EINA_FALSE);
    EINA_SAFETY_ON_NULL_RETURN_VAL(contents, EINA_FALSE);
    EINA_SAFETY_ON_NULL_RETURN_VAL(unreachable_uri, EINA_FALSE);
    return _ewk_frame_contents_set_internal
        (sd, contents, contents_size, mime_type, encoding, base_uri,
         unreachable_uri);
}