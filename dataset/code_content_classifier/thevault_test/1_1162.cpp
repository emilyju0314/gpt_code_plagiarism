FacebookNotificationInterface::FacebookNotificationInterface(QObject *parent)
    : IdentifiableContentItemInterface(*(new FacebookNotificationInterfacePrivate(this)), parent)
{
// <<< constructor
    Q_D(FacebookNotificationInterface);
    d->from = new FacebookObjectReferenceInterface(this);
    d->to = new FacebookObjectReferenceInterface(this);
    d->application = new FacebookObjectReferenceInterface(this);
// >>> constructor
}