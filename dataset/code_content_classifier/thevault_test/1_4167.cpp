static bool isInteger(std::string const& word, int& val)
{
    bool isNumber = true;
    for(std::string::const_iterator k = word.begin(); k != word.end(); ++k)
        isNumber = (isNumber && isdigit(*k));

    if (isNumber)
        val = strtol(word.c_str(), nullptr, 10);

    return isNumber;
}