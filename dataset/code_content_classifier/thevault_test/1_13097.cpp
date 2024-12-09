int XConfig::GetInt(const char * name, int defaultP)
{
    int r;

    LoadInt(name, &r, defaultP);

    return r;
}