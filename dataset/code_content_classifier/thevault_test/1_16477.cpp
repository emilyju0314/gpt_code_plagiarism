Eina_Bool ewk_view_navigation_policy_decision(Evas_Object* o, Ewk_Frame_Resource_Request* request)
{
    EWK_VIEW_SD_GET_OR_RETURN(o, sd, EINA_TRUE);
    EINA_SAFETY_ON_NULL_RETURN_VAL(sd->api, EINA_TRUE);

    if (!sd->api->navigation_policy_decision)
        return EINA_TRUE;

    return sd->api->navigation_policy_decision(sd, request);
}