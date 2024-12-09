int CBIntPrefsFunc (const char *, [[maybe_unused]] const char * item, int defaultVal)
{
    // We always want to replace dataRefs and textures upon load to make the most out of the .obj files
    if (!strcmp(item, XPMP_CFG_ITM_REPLDATAREFS)) return 1;
    if (!strcmp(item, XPMP_CFG_ITM_REPLTEXTURE)) return 1;      // actually...this is ON by default anyway, just to be sure
#if DEBUG
    // in debug version of the plugin we provide most complete log output
    if (!strcmp(item, XPMP_CFG_ITM_MODELMATCHING)) return 1;
    if (!strcmp(item, XPMP_CFG_ITM_LOGLEVEL)) return 0;       // DEBUG logging level
#endif
    // Otherwise we just accept defaults
    return defaultVal;
}