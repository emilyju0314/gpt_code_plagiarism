void CSLObj::Invalidate ()
{
    xpObj       = NULL;
    xpObjState  = OLS_INVALID;
    LOG_MSG(logERR, ERR_OBJ_NOT_LOADED, cslKey.c_str(), StripXPSysDir(path).c_str());
}