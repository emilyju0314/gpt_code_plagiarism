void ewk_frame_core_gone(Evas_Object* o)
{
    DBG("o=%p", o);
    EWK_FRAME_SD_GET_OR_RETURN(o, sd);
    sd->frame = 0;
}