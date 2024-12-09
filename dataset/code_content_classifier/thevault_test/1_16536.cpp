struct RenderThemeEfl::ThemePartCacheEntry* RenderThemeEfl::cacheThemePartReset(FormType type, struct RenderThemeEfl::ThemePartCacheEntry* entry)
{
    if (!themePartCacheEntryReset(entry, type)) {
        entry->type = FormTypeLast; // invalidate
        m_partCache.append(entry);
        return 0;
    }
    entry->type = type;
    m_partCache.prepend(entry);
    return entry;
}