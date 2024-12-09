QQmlListProperty<FacebookPhotoTagInterface> FacebookPhotoInterface::tags()
{
    return QQmlListProperty<FacebookPhotoTagInterface>(
                this, 0,
                &FacebookPhotoInterfacePrivate::tags_append,
                &FacebookPhotoInterfacePrivate::tags_count,
                &FacebookPhotoInterfacePrivate::tags_at,
                &FacebookPhotoInterfacePrivate::tags_clear);
}