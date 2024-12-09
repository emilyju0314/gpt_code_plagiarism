bool FacebookPhotoInterface::removeComment(const QString &commentIdentifier)
{
// <<< removeComment
    Q_D(FacebookPhotoInterface);
    bool requestMade = d->request(IdentifiableContentItemInterfacePrivate::Delete,
                                  commentIdentifier);

    if (!requestMade)
        return false;

    d->action = FacebookInterfacePrivate::DeleteCommentAction;
    d->connectFinishedAndErrors();
    return true;
// >>> removeComment
}