bool XConfig::GetBool(const char * name, bool defaultP)
{
    bool r;

    LoadBool(name, &r, defaultP);

    return r;
}