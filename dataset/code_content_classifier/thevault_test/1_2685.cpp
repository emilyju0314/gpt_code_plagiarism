std::string gjAPI::UtilEscapeString(const std::string& sString)
{
    std::string sOutput = "";

    // loop through input string
    for(size_t i = 0, ie = sString.length(); i < ie; ++i)
    {
        // check the character type
        if
        (
            (48 <= sString[i] && sString[i] <=  57) || // 0-9
            (65 <= sString[i] && sString[i] <=  90) || // ABC...XYZ
            (97 <= sString[i] && sString[i] <= 122) || // abc...xyz
            (
                sString[i] == '~' || sString[i] == '.'  ||
                sString[i] == '-' || sString[i] == '_'
            )
        )
        {
            // add valid character
            sOutput += sString[i];
        }
        else
        {
            // convert character to hexadecimal value
            sOutput += "%" + gjAPI::UtilCharToHex(sString[i]);
        }
    }

    return sOutput;
}