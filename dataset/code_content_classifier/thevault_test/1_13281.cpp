void DVB::preMainLoop()
{
    // preparation staff
    ModuleWithDB::preMainLoop();
    m_processor->clean();
}