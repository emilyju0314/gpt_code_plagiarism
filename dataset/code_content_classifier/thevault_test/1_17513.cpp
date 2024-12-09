XPLMObjectRef CSLObj::GetAndLoadObj ()
{
    // (Try) Loading, then return what we have, even if it is NULL
    Load();
    return xpObj;
}