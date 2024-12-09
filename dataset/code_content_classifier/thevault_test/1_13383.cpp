void TestFireWire::testInitial()
{
    test::printOut("\n\tInitial test ...");
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
    CPPUNIT_ASSERT(test_module->getDisappearCount1() == 0);
    CPPUNIT_ASSERT(test_module->getAppearCount2() == 0);
    CPPUNIT_ASSERT(test_module->getDisappearCount2() == 0);


    // db keeps one record
    db::DB db(test::Factory::instance());
    db.connect();

    db::Parameters params;
    db::ResultVector rv = db.callSelect("klk_ieee1394_list", params, NULL);
    CPPUNIT_ASSERT(rv.size() == 1);
    db::Result res = *rv.begin();
    // SELECT uuid, name, description FROM klk_ieee1394;
    CPPUNIT_ASSERT(res["uuid"].toString() == TESTUUID1);
    CPPUNIT_ASSERT(res["name"].toString() == TESTNAME1);
    CPPUNIT_ASSERT(res["description"].toString() == TESTDESCR1);
}