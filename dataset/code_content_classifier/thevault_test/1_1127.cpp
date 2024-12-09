int TwitterInterfacePrivate::detectTypeFromData(const QVariantMap &data) const
{
    // it's possible that we've already tagged the type already
    if (data.contains(NEMOQMLPLUGINS_SOCIAL_CONTENTITEMTYPE)) {
        TwitterInterface::ContentItemType taggedType = static_cast<TwitterInterface::ContentItemType>(data.value(NEMOQMLPLUGINS_SOCIAL_CONTENTITEMTYPE).toInt());
        if (taggedType > TwitterInterface::Unknown) {
            return taggedType;
        }
    }

    return TwitterInterface::Unknown;
}