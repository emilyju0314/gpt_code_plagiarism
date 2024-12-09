std::string gjAPI::UtilIntToString(const int iInt)
{
    char acBuffer[32];
    std::sprintf(acBuffer, "%d", iInt);

    return acBuffer;
}