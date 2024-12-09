bool FacebookPhotoInterface::untagUser(const QString &userId)
{
// <<< untagUser
    Q_D(FacebookPhotoInterface);
    QVariantMap extraData;
    extraData.insert("to", userId);

    // try to find which tag will be removed if it succeeds
    int tempPendingTagToRemoveIndex = -1;
    for (int i = 0; i < d->tags.count(); ++i) {
        QString tagUserIdentifier = d->tags.at(i)->userIdentifier();
        if (!tagUserIdentifier.isEmpty() && tagUserIdentifier == userId) {
            tempPendingTagToRemoveIndex = i;
            break;
        }
    }

    // possible that it's ok to not exist, since we might be out of sync with reality.
    if (tempPendingTagToRemoveIndex == -1)
        qWarning() << Q_FUNC_INFO << "Unknown tag specified for removal";

    bool requestMade = d->request(IdentifiableContentItemInterfacePrivate::Delete,
                                  identifier(), QLatin1String("tags"),
                                  QStringList(), QVariantMap(), extraData);

    if (!requestMade)
        return false;

    d->action = FacebookInterfacePrivate::DeleteTagAction;
    d->pendingTagToRemoveIndex = tempPendingTagToRemoveIndex;
    d->connectFinishedAndErrors();
    return true;
// >>> untagUser
}