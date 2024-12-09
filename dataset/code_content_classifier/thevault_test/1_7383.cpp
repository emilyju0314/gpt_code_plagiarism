int account::delete_key(string& input)
{
    Address a;
    if (!userToAddress(input,a))
    {
        m_keyManager.kill(a);
        return 0;
    }
    return -1;
}