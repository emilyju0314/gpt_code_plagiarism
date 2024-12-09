std::string GetMiscNetwTimeStr (float _time)
{
    char aszTimeStr[20];
    if (std::isnan(_time))
        _time = GetMiscNetwTime();
    
    const unsigned runH = unsigned(_time / 3600.0f);
    _time -= runH * 3600.0f;
    const unsigned runM = unsigned(_time / 60.0f);
    _time -= runM * 60.0f;
    
    snprintf(aszTimeStr, sizeof(aszTimeStr), "%u:%02u:%06.3f",
             runH, runM, _time);
    return aszTimeStr;
}