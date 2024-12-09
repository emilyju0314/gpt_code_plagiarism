void QLibHomeScreen::replyShowWindow(QString application_id, QString reply)
{
    if(reply.isNull())
        mp_hs->replyShowWindow(application_id.toStdString().c_str(), nullptr);
    else
        mp_hs->replyShowWindow(application_id.toStdString().c_str(), json_tokener_parse(reply.toStdString().c_str()));
}