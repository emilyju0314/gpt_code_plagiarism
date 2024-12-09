void QLibHomeScreen::init(int port, const QString &token)
{
    HMI_DEBUG("qlibhomescreen", "called.");
    string ctoken = token.toStdString();
    mp_hs = new LibHomeScreen();
    mp_hs->init(port, ctoken.c_str());

    myThis = this;
}