void QLibHomeScreen::tapShortcut(QString application_id)
{
    HMI_DEBUG("qlibhomescreen","tapShortcut %s", application_id.toStdString().c_str());
    mp_hs->showWindow(application_id.toStdString().c_str(), nullptr);
}