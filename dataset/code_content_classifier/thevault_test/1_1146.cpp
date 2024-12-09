bool FacebookPhotoInterface::tagUser(const QString &userId, float xOffset, float yOffset)
{
// <<< tagUser
    Q_D(FacebookPhotoInterface);
    QVariantMap postData;
    postData.insert("id", userId);
    if (xOffset != -1)
        postData.insert("x", QString::number(xOffset));
    if (yOffset != -1)
        postData.insert("y", QString::number(yOffset));

    bool requestMade = d->request(IdentifiableContentItemInterfacePrivate::Post,
                                  identifier(), QLatin1String("tags"),
                                  QStringList(), postData);

    if (!requestMade)
        return false;

    d->action = FacebookInterfacePrivate::TagAction;
    d->connectFinishedAndErrors();
    return true;
// >>> tagUser
}