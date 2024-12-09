Installer* Factory::getInstaller()
{
    try
    {
        if (m_installer == NULL)
        {
            m_installer = new Installer(this);
        }
    }
    catch(const std::bad_alloc&)
    {
        throw Exception(__FILE__, __LINE__, err::MEMORYALLOC);
    }
    return m_installer;
}