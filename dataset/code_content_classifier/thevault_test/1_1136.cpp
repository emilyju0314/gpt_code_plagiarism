bool IdentifiableContentItemInterface::reload(const QStringList &whichFields)
{
    Q_D(IdentifiableContentItemInterface);
    if (!d->request(IdentifiableContentItemInterfacePrivate::Get, d->identifier,
                    QString(), whichFields))
        return false;

    connect(d->reply(), SIGNAL(finished()), this, SLOT(reloadHandler()));
    d->connectErrors();
    return true;
}