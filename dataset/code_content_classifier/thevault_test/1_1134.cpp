SocialNetworkInterface::SocialNetworkInterface(QObject *parent)
    : QObject(parent), d_ptr(new SocialNetworkInterfacePrivate(this))
{
    Q_D(SocialNetworkInterface);
    d->networkAccessManager = new QNetworkAccessManager(this);
}