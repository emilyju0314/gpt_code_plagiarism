int CBIntPrefsFunc (const char *, [[maybe_unused]] const char * item, int defaultVal)
{
    // We always want to replace dataRefs and textures upon load to make the most out of the .obj files
    if (!strcmp(item, XPMP_CFG_ITM_REPLDATAREFS))   return rcGlob.mergedS.bObjReplDataRefs; // taken from sending plugins
    if (!strcmp(item, XPMP_CFG_ITM_REPLTEXTURE))    return rcGlob.mergedS.bObjReplTextures; // taken from sending plugins
    if (!strcmp(item, XPMP_CFG_ITM_CLAMPALL))       return 0;                               // Never needed: The defining coordinates are sent to us, don't interpret them here in any way
    if (!strcmp(item, XPMP_CFG_ITM_HANDLE_DUP_ID))  return 1;                               // must be on: if receiving from different plugins we can easily run in duplicate ids, which shall be handled
    if (!strcmp(item, XPMP_CFG_ITM_SUPPORT_REMOTE)) return -1;                              // We don't want this plugin to ever _send_ traffic!
    if (!strcmp(item, XPMP_CFG_ITM_LOGLEVEL))       return (int)rcGlob.mergedS.logLvl;      // taken from sending plugins
    if (!strcmp(item, XPMP_CFG_ITM_MODELMATCHING))  return rcGlob.mergedS.bLogMdlMatch;     // taken from sending plugins
    // Otherwise we just accept defaults
    return defaultVal;
}