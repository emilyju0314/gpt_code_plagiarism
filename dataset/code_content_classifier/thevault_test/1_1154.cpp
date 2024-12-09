QQmlListProperty<FacebookPhotoImageInterface> FacebookPhotoInterface::images()
{
    return QQmlListProperty<FacebookPhotoImageInterface>(
                this, 0,
                &FacebookPhotoInterfacePrivate::images_append,
                &FacebookPhotoInterfacePrivate::images_count,
                &FacebookPhotoInterfacePrivate::images_at,
                &FacebookPhotoInterfacePrivate::images_clear);
}