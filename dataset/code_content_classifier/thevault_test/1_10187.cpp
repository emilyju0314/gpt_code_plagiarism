void QLibHomeScreen::showInformation(QString info)
{
	struct json_object* j_obj = json_object_new_object();
	struct json_object* val = json_object_new_string(info.toStdString().c_str());
	json_object_object_add(j_obj, "info", val);

    mp_hs->showInformation(j_obj);
}