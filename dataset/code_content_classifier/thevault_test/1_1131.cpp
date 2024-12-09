QNetworkReply * SocialNetworkInterfacePrivate::postRequest(const QString &objectIdentifier,
                                                           const QString &extraPath,
                                                           const QVariantMap &data,
                                                           const QVariantMap &extraData)
{
    Q_UNUSED(objectIdentifier)
    Q_UNUSED(extraPath)
    Q_UNUSED(data)
    Q_UNUSED(extraData)
    qWarning() << Q_FUNC_INFO << "Error: this function MUST be implemented by derived types!";
    return 0;
}