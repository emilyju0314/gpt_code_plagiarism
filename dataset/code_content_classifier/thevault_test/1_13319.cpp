void TestScan::loadModules()
{
    CPPUNIT_ASSERT(m_modfactory);

    // load module
    m_modfactory->load(MODID);
    // create devices
    createDev();
    // set processor
    m_processor = TestProcessorPtr(new TestProcessor());
    getModule<Scan>(MODID)->m_thread->registerProcessor(m_processor);
}