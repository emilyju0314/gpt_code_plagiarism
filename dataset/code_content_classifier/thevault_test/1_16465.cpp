Evas_Object* ewk_view_window_create(Evas_Object* o, Eina_Bool javascript, const WebCore::WindowFeatures* coreFeatures)
{
    EWK_VIEW_SD_GET_OR_RETURN(o, sd, 0);

    if (!sd->api->window_create)
        return o;

    Ewk_Window_Features* window_features = ewk_window_features_new_from_core(coreFeatures);
    Evas_Object* view = sd->api->window_create(sd, javascript, window_features);
    ewk_window_features_unref(window_features);

    return view;
}