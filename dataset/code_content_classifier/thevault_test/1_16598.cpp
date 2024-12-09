Evas_Object* ewk_frame_child_find(Evas_Object* o, const char* name)
{
    EWK_FRAME_SD_GET_OR_RETURN(o, sd, 0);
    EINA_SAFETY_ON_NULL_RETURN_VAL(name, 0);
    EINA_SAFETY_ON_NULL_RETURN_VAL(sd->frame, 0);
    WTF::String s = WTF::String::fromUTF8(name);
    return kit(sd->frame->tree()->find(WTF::AtomicString(s)));
}