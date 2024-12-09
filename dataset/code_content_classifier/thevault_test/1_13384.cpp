void TestFireWire::testDetection()
{
    test::printOut("\n\tDetection test ...");

    boost::shared_ptr<TestHelpModule> test_module =
        getModule<TestHelpModule>(TEST_MOD_ID);
    CPPUNIT_ASSERT(test_module);
    test_module->clear();
    boost::shared_ptr<FireWire> module = getModule<FireWire>(MODID);
    CPPUNIT_ASSERT(module);
    module->m_update =
        boost::bind(&TestFireWire::getFullDVInfoSet);
    sleep(CHECKINTERVAL + 2);
    // list not empty
    DVInfoList list = module->m_info.getInfoList();
    CPPUNIT_ASSERT(list.size() == 2);
    DVInfoList::iterator find1 = std::find_if(
        list.begin(), list.end(),
        boost::bind(mod::FindInfoByUUID<>(), _1, TESTUUID1));
    CPPUNIT_ASSERT(find1 != list.end());
    CPPUNIT_ASSERT((*find1)->getUUID() == TESTUUID1);
    CPPUNIT_ASSERT((*find1)->getName() == TESTNAME1);
    CPPUNIT_ASSERT((*find1)->getDescription() == TESTDESCR1);
    DVInfoList::iterator find2 = std::find_if(
        list.begin(), list.end(),
        boost::bind(mod::FindInfoByUUID<>(), _1, TESTUUID2));
    CPPUNIT_ASSERT(find2 != list.end());
    CPPUNIT_ASSERT((*find2)->getUUID() == TESTUUID2);
    CPPUNIT_ASSERT((*find2)->getName() == TESTNAME2);
    CPPUNIT_ASSERT((*find2)->getDescription() == TESTDESCR2);

    // check detection state
    CPPUNIT_ASSERT(test_module->getAppearCount1() == 1);
    CPPUNIT_ASSERT(test_module->getDisappearCount1() == 0);
    CPPUNIT_ASSERT(test_module->getAppearCount2() == 1);
    CPPUNIT_ASSERT(test_module->getDisappearCount2() == 0);

    // test records at the DB
    testFullDB();
}