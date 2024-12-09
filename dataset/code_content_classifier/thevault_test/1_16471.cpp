Eina_Bool ewk_view_should_interrupt_javascript(Evas_Object* o)
{
    DBG("o=%p", o);
    EWK_VIEW_SD_GET_OR_RETURN(o, sd, EINA_FALSE);
    EINA_SAFETY_ON_NULL_RETURN_VAL(sd->api, EINA_FALSE);

    if (!sd->api->should_interrupt_javascript)
        return EINA_FALSE;

    return sd->api->should_interrupt_javascript(sd);
}