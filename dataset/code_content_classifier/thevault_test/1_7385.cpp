int account::userToAddress(std::string const& input,Address& a)
{
    if (h128 u = fromUUID(input))
    {	
        a = m_keyManager.address(u);
        return 0;
    }

    try
    {
        a = toAddress(input);
        return 0;
    }
    catch(...){}

    for (Address const& a_tmep: m_keyManager.accounts())
        if (m_keyManager.accountName(a) == input)
            a = a_tmep;
    return -1;
}