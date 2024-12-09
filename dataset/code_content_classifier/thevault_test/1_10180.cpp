int QLibHomeScreen::onScreenMessage(const QString &message)
{
    HMI_DEBUG("qlibhomescreen", "called.");
    string str = message.toStdString();
    return mp_hs->onScreenMessage(str.c_str());
}