std::string gjAPI::UtilCharToHex(const char cChar)
{
    int iValue = (int)cChar;
    if(iValue < 0) iValue += 256;

    char acBuffer[8];
    std::sprintf(acBuffer, "%02X", iValue);

    return acBuffer;
}