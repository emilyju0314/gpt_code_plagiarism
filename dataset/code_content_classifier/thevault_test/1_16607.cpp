Eina_Bool ewk_frame_text_search(const Evas_Object* o, const char* string, Eina_Bool case_sensitive, Eina_Bool forward, Eina_Bool wrap)
{
    EWK_FRAME_SD_GET_OR_RETURN(o, sd, EINA_FALSE);
    EINA_SAFETY_ON_NULL_RETURN_VAL(sd->frame, EINA_FALSE);
    EINA_SAFETY_ON_NULL_RETURN_VAL(string, EINA_FALSE);

    return sd->frame->editor()->findString(WTF::String::fromUTF8(string), forward, case_sensitive, wrap, true);
}