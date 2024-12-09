FacebookCommentInterface::FacebookCommentInterface(QObject *parent)
    : IdentifiableContentItemInterface(*(new FacebookCommentInterfacePrivate(this)), parent)
{
// <<< constructor
    Q_D(FacebookCommentInterface);
    d->from = new FacebookObjectReferenceInterface(this);
// >>> constructor
}