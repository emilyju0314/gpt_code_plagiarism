ContentItemInterface * SocialNetworkInterfacePrivate::contentItemFromData(const QVariantMap &data,
                                                                          QObject *parent) const
{
    Q_UNUSED(data)
    Q_UNUSED(parent)
    qWarning() << Q_FUNC_INFO << "Error: this function MUST be implemented by derived types!";
    return 0;
}