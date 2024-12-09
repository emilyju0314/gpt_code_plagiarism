void CSLObj::Load ()
{
    // only if not already requested or even available
    if (GetObjState() != OLS_UNAVAIL &&
        GetObjState() != OLS_COPYING)
        return;
    
    // If needed it is now the time to copy the .obj file
    if (!TriggerCopyAndReplace())
        return;
    
    // Prepare to load the CSL model from the .obj file
    LOG_MSG(logDEBUG, DEBUG_OBJ_LOADING,
            cslKey.c_str(), StripXPSysDir(path).c_str());
    
    // Based on experience it seems XPLMLoadObjectAsync() does not
    // properly support HFS file paths. It just replaces all ':' with '/',
    // which is incomplete.
    // That's why we store paths to .obj already in POSIX format:
    XPLMLoadObjectAsync(path.c_str(),                   // path to .obj
                        &XPObjLoadedCB,                 // static callback function
                        new pairOfStrTy(cslKey.c_str(), // _copy_ of the key string
                                        path.c_str()));
    xpObjState = OLS_LOADING;
}