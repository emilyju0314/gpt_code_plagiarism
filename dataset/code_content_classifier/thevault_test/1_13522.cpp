bool Result::operator==(const Pair& pair) const throw()
{
    try
    {
        ResultMap::const_iterator i = m_results.find(pair.first);
        if (i != m_results.end())
        {
            return (i->second.toString() == pair.second);
        }
    }
    catch(...)
    {
        // nothing to do
        return false;
    }
    return false;
}