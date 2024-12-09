bool gjAPI::UtilCompStringsCaseInsensitive(const std::string& sFirst, const std::string& sSecond)
{
    if(sFirst.length() != sSecond.length())
        return false;

    for(size_t i = 0u, ie = sFirst.length(); i < ie; ++i)
    {
        if(tolower(sFirst[i]) != tolower(sSecond[i]))
            return false;
    }

    return true;
}