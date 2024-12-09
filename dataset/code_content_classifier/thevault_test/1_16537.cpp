struct RenderThemeEfl::ThemePartCacheEntry* RenderThemeEfl::cacheThemePartGet(FormType type, const IntSize& size)
{
    Vector<struct ThemePartCacheEntry *>::iterator itr, end;
    struct ThemePartCacheEntry *ce_last_size = 0;
    int i, idxLastSize = -1;

    itr = m_partCache.begin();
    end = m_partCache.end();
    for (i = 0; itr != end; i++, itr++) {
        struct ThemePartCacheEntry *entry = *itr;
        if (entry->size == size) {
            if (entry->type == type)
                return entry;
            ce_last_size = entry;
            idxLastSize = i;
        }
    }

    if (m_partCache.size() < RENDER_THEME_EFL_PART_CACHE_MAX)
        return cacheThemePartNew(type, size);

    if (ce_last_size && ce_last_size != m_partCache.first()) {
        m_partCache.remove(idxLastSize);
        return cacheThemePartReset(type, ce_last_size);
    }

    ThemePartCacheEntry* entry = m_partCache.last();
    m_partCache.removeLast();
    return cacheThemePartResizeAndReset(type, size, entry);
}