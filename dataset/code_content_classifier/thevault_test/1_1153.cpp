QQmlListProperty<FacebookNameTagInterface> FacebookPhotoInterface::nameTags()
{
    return QQmlListProperty<FacebookNameTagInterface>(
                this, 0,
                &FacebookPhotoInterfacePrivate::name_tags_append,
                &FacebookPhotoInterfacePrivate::name_tags_count,
                &FacebookPhotoInterfacePrivate::name_tags_at,
                &FacebookPhotoInterfacePrivate::name_tags_clear);
}