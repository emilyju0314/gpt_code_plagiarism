void QLibHomeScreen::showNotification(QString icon, QString text)
{
	struct json_object* j_obj = json_object_new_object();
	struct json_object* val_icon = json_object_new_string(icon.toStdString().c_str());
	struct json_object* val_text = json_object_new_string(text.toStdString().c_str());
	json_object_object_add(j_obj, "icon", val_icon);
	json_object_object_add(j_obj, "text", val_text);

    mp_hs->showNotification(j_obj);
}