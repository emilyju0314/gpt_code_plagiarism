int QLibHomeScreen::subscribe(const QString &evetName)
{
    HMI_DEBUG("qlibhomescreen", "called.");
    string str = evetName.toStdString();
    return mp_hs->subscribe(str);
}