void ewk_frame_paint_full_set(Evas_Object* o, Eina_Bool flag)
{
    EWK_FRAME_SD_GET_OR_RETURN(o, sd);
    EINA_SAFETY_ON_NULL_RETURN(sd->frame);
    EINA_SAFETY_ON_NULL_RETURN(sd->frame->view());
    sd->frame->view()->setPaintsEntireContents(flag);
}