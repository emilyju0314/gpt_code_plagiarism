FacebookPhotoInterface::FacebookPhotoInterface(QObject *parent)
    : IdentifiableContentItemInterface(*(new FacebookPhotoInterfacePrivate(this)), parent)
{
// <<< constructor
    Q_D(FacebookPhotoInterface);
    d->from = new FacebookObjectReferenceInterface(this);
// >>> constructor
}