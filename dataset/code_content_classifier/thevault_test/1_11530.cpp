void CIMAPBodyStruct::parseNext(std::string &part, std::string &value)
    {
        if (part.empty())
        {
            return;
        }
        else if (part[0] == '\"')
        {
            value = CIMAPParse::stringBetween(part, '\"', '\"');
            part = part.substr(value.length() + 3);
        }
        else if (part[0] == '(')
        {
            value = CIMAPParse::stringList(part);
            part = part.substr(value.length() + 1);
        }
        else if (std::isdigit(part[0]))
        {
            value = part.substr(0, part.find_first_of(' '));
            part = part.substr(part.find_first_of(' ') + 1);
        }
        else if (CIMAPParse::stringStartsWith(part, kNIL))
        {
            value = kNIL;
            part = part.substr(value.length() + 1);
        }
        else
        {
            throw Exception("error while parsing body structure [" + part + "]");
        }
    }