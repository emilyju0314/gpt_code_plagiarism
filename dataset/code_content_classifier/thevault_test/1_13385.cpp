void TestFireWire::testRemove()
{
    test::printOut("\n\tRemove test ...");

    boost::shared_ptr<TestHelpModule> test_module =
        getModule<TestHelpModule>(TEST_MOD_ID);
    CPPUNIT_ASSERT(test_module);
    test_module->clear();

    boost::shared_ptr<FireWire> module = getModule<FireWire>(MODID);
    CPPUNIT_ASSERT(module);
    module->m_update =
        boost::bind(&TestFireWire::getRemoveDVInfoSet);
    sleep(CHECKINTERVAL + 2);
    // list is empty
    DVInfoList list = module->m_info.getInfoList();
    CPPUNIT_ASSERT(list.empty() == true);

    // check detection state
    CPPUNIT_ASSERT(test_module->getAppearCount1() == 0);
    CPPUNIT_ASSERT(test_module->getDisappearCount1() == 1);
    CPPUNIT_ASSERT(test_module->getAppearCount2() == 0);
    CPPUNIT_ASSERT(test_module->getDisappearCount2() == 1);

    // disappear should not change because
    // no any existent devs were disapeared
    sleep(CHECKINTERVAL + 2);
    CPPUNIT_ASSERT(test_module->getAppearCount1() == 0);
    CPPUNIT_ASSERT(test_module->getDisappearCount1() == 1);
    CPPUNIT_ASSERT(test_module->getAppearCount2() == 0);
    CPPUNIT_ASSERT(test_module->getDisappearCount2() == 1);

    testFullDB();
}