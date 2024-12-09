unsigned int ewk_frame_text_matches_mark(Evas_Object* o, const char* string, Eina_Bool case_sensitive, Eina_Bool highlight, unsigned int limit)
{
    EWK_FRAME_SD_GET_OR_RETURN(o, sd, 0);
    EINA_SAFETY_ON_NULL_RETURN_VAL(sd->frame, EINA_FALSE);
    EINA_SAFETY_ON_NULL_RETURN_VAL(string, 0);

    sd->frame->editor()->setMarkedTextMatchesAreHighlighted(highlight);
    return sd->frame->editor()->countMatchesForText(WTF::String::fromUTF8(string), case_sensitive, limit, true);
}