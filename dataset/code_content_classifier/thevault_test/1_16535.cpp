struct RenderThemeEfl::ThemePartCacheEntry* RenderThemeEfl::cacheThemePartNew(FormType type, const IntSize& size)
{
    struct ThemePartCacheEntry *entry = new struct ThemePartCacheEntry;

    if (!entry) {
        EINA_LOG_ERR("could not allocate ThemePartCacheEntry.");
        return 0;
    }

    entry->ee = ecore_evas_buffer_new(size.width(), size.height());
    if (!entry->ee) {
        EINA_LOG_ERR("ecore_evas_buffer_new(%d, %d) failed.",
                     size.width(), size.height());
        delete entry;
        return 0;
    }

    entry->o = edje_object_add(ecore_evas_get(entry->ee));
    ASSERT(entry->o);
    if (!themePartCacheEntryReset(entry, type)) {
        evas_object_del(entry->o);
        ecore_evas_free(entry->ee);
        delete entry;
        return 0;
    }

    if (!themePartCacheEntrySurfaceCreate(entry)) {
        evas_object_del(entry->o);
        ecore_evas_free(entry->ee);
        delete entry;
        return 0;
    }

    evas_object_resize(entry->o, size.width(), size.height());
    evas_object_show(entry->o);

    entry->type = type;
    entry->size = size;

    m_partCache.prepend(entry);
    return entry;
}