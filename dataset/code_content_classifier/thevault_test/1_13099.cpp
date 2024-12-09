float XConfig::GetFloat(const char * name, float defaultP)
{
    float r;

    LoadFloat(name, &r, defaultP);

    return r;
}