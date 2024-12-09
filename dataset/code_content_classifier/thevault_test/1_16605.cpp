char* ewk_frame_selection_get(const Evas_Object* o)
{
    EWK_FRAME_SD_GET_OR_RETURN(o, sd, 0);
    EINA_SAFETY_ON_NULL_RETURN_VAL(sd->frame, 0);
    WTF::CString s = sd->frame->editor()->selectedText().utf8();
    if (s.isNull())
        return 0;
    return strdup(s.data());
}