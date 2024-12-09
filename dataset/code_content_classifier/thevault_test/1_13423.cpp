void TrapTest::testCommonTraps()
{
    test::printOut("\nSNMP common traps test ... ");

    CPPUNIT_ASSERT(!DB_FAILED.empty());
    CPPUNIT_ASSERT(!MODULE_LOAD_FAILED.empty());
    CPPUNIT_ASSERT(!MODULE_DNT_RESPONDE.empty());

    // Test module load failure
    IFactory *factory = test::Factory::instance();
    CPPUNIT_ASSERT(factory != NULL);
    const std::string wrong("wrongid");
    try
    {
        factory->getModuleFactory()->load(wrong);
    }
    catch(const Exception&)
    {
        // nothing to do
        // we should be here
    }
    sleep(5);
    test::TrapInfoVector result = m_receiver.getTraps();
    CPPUNIT_ASSERT(result.empty() == false);
    CPPUNIT_ASSERT(result.size() == 1);
    CPPUNIT_ASSERT(result[0].getValue() == wrong);
    CPPUNIT_ASSERT(result[0].getOID() == ".1.3.6.1.4.1.31106.1.2");

    // FIXME!!! add others traps test
}