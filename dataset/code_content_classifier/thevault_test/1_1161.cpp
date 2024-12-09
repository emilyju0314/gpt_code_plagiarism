bool FacebookAlbumInterface::removePhoto(const QString &photoIdentifier)
{
// <<< removePhoto
    Q_D(FacebookAlbumInterface);
    bool requestMade = d->request(IdentifiableContentItemInterfacePrivate::Delete, photoIdentifier);

    if (!requestMade)
        return false;

    d->action = FacebookInterfacePrivate::DeletePhotoAction;
    d->connectFinishedAndErrors();
    return true;
// >>> removePhoto
}