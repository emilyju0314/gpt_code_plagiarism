int
checkKeyword(string& id)
{
    StringTokenMap::const_iterator pos = keywordMap.find(id);
    if(pos != keywordMap.end())
    {
        if(pos->first != id)
        {
            string msg;
            msg = "illegal identifier: `" + id + "' differs from keyword `";
            msg += pos->first + "' only in capitalization";
            unit->error(msg);
            id = pos->first;
        }
        return pos->second;
    }
    return checkIdentifier(id);
}