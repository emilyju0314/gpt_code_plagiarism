void TestBase::loadModules()
{
    CPPUNIT_ASSERT(m_modfactory);

    // load the transcoder
    m_modfactory->load(MODID);
}