QNetworkReply * SocialNetworkInterfacePrivate::deleteRequest(const QString &objectIdentifier,
                                                             const QString &extraPath,
                                                             const QVariantMap &extraData)
{
    Q_UNUSED(objectIdentifier)
    Q_UNUSED(extraPath)
    Q_UNUSED(extraData)
    qWarning() << Q_FUNC_INFO << "Error: this function MUST be implemented by derived types!";
    return 0;
}