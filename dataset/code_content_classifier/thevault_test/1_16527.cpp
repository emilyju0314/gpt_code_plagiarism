static AtkAttributeSet* attributeSetDifference(AtkAttributeSet* a1, AtkAttributeSet* a2)
{
    if (!a2)
        return a1;

    AtkAttributeSet* i = a1;
    AtkAttributeSet* found;
    AtkAttributeSet* toDelete = 0;

    while (i) {
        found = g_slist_find_custom(a2, i->data, (GCompareFunc)compareAttribute);
        if (found) {
            AtkAttributeSet* t = i->next;
            toDelete = g_slist_prepend(toDelete, i->data);
            a1 = g_slist_delete_link(a1, i);
            i = t;
        } else
            i = i->next;
    }

    atk_attribute_set_free(a2);
    atk_attribute_set_free(toDelete);
    return a1;
}