const char* ewk_frame_name_get(const Evas_Object* o)
{
    EWK_FRAME_SD_GET_OR_RETURN(o, sd, 0);

    if (sd->name)
        return sd->name;

    if (!sd->frame) {
        ERR("could not get name of uninitialized frame.");
        return 0;
    }

    WTF::String s = sd->frame->tree()->uniqueName();
    WTF::CString cs = s.utf8();
    sd->name = eina_stringshare_add_length(cs.data(), cs.length());
    return sd->name;
}