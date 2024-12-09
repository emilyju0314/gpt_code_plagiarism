void DVB::postMainLoop() throw()
{
    m_processor->clean();
    ModuleWithDB::postMainLoop();
}