bool SorterInterface::firstLessThanSecond(const QVariantMap &first, const QVariantMap &second) const
{
    if (first.empty() && !second.empty()) {
         return true;
    }

    if (second.empty()) {
         return false;
    }

    return first.value(NEMOQMLPLUGINS_SOCIAL_CONTENTITEMTYPE).toInt()
           < second.value(NEMOQMLPLUGINS_SOCIAL_CONTENTITEMTYPE).toInt();
}