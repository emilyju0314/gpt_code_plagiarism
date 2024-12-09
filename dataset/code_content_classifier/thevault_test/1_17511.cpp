const char* LogGetString (const char* szPath, int ln, const char* szFunc,
                          logLevelTy lvl, const char* szMsg, va_list args )
{
     static char aszMsg[2048];
     float runS = GetMiscNetwTime();
     const unsigned runH = unsigned(runS / 3600.0f);
     runS -= runH * 3600.0f;
     const unsigned runM = unsigned(runS / 60.0f);
     runS -= runM * 60.0f;

    // prepare timestamp
    if ( lvl < logMSG )                             // normal messages without, all other with location info
    {
        const char* szFile = strrchr(szPath, PATH_DELIM_STD);  // extract file from path
        if ( !szFile ) szFile = szPath; else szFile++;
        snprintf(aszMsg, sizeof(aszMsg), "%u:%02u:%06.3f %s %s %s:%d/%s: ",
                 runH, runM, runS,                  // Running time stamp
                 REMOTE_CLIENT_LOG, LOG_LEVEL[lvl],
                 szFile, ln, szFunc);
    }
    else
        snprintf(aszMsg, sizeof(aszMsg), "%u:%02u:%06.3f %s: ",
                 runH, runM, runS,                  // Running time stamp
                 REMOTE_CLIENT_LOG);
    
    // append given message
    if (args) {
        vsnprintf(&aszMsg[strlen(aszMsg)],
                  sizeof(aszMsg)-strlen(aszMsg)-1,      // we save one char for the CR
                  szMsg,
                  args);
    }

    // ensure there's a trailing CR
    size_t l = strlen(aszMsg);
    if ( aszMsg[l-1] != '\n' )
    {
        aszMsg[l]   = '\n';
        aszMsg[l+1] = 0;
    }

    // return the static buffer
    return aszMsg;
}