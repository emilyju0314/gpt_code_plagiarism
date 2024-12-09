FacebookAlbumInterface::FacebookAlbumInterface(QObject *parent)
    : IdentifiableContentItemInterface(*(new FacebookAlbumInterfacePrivate(this)), parent)
{
// <<< constructor
    Q_D(FacebookAlbumInterface);
    d->from = new FacebookObjectReferenceInterface(this);
// >>> constructor
}