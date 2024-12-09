bool IdentifiableContentItemInterface::remove()
{
    Q_D(IdentifiableContentItemInterface);
    if (!d->request(IdentifiableContentItemInterfacePrivate::Delete, d->identifier))
        return false;

    connect(d->reply(), SIGNAL(finished()), this, SLOT(removeHandler()));
    d->connectErrors();
    return true;
}