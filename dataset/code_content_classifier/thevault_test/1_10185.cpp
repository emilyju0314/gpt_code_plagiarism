void QLibHomeScreen::showWindow(QString application_id, QString area)
{
    if(area.isNull()) {
        mp_hs->showWindow(application_id.toStdString().c_str(), nullptr);
    } else {
        struct json_object *j_obj = json_object_new_object();
        struct json_object *value = json_object_new_string(area.toStdString().c_str());
        json_object_object_add(j_obj, "area", value);
        mp_hs->showWindow(application_id.toStdString().c_str(), j_obj);
    }
}