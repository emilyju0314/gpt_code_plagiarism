void TestRouteInfo::test()
{
    test::printOut("\nNetwork route info test ... ");

    // check that we have our test dev
    IFactory* factory = test::Factory::instance();
    CPPUNIT_ASSERT(factory);
    CPPUNIT_ASSERT(m_dev);

    RouteInfo info1(TESTROUTE1_UUID, TESTROUTE1_NAME,
                    TESTROUTE1_ADDR, TESTROUTE1_PORT,
                    TCPIP,
                    msg::key::NETUNICAST,
                    m_dev, factory);

    test::printOut("\n\tBase ... ");

    // should not be locked
    CPPUNIT_ASSERT(info1.isInUse() == false);

    // lock it
    info1.setInUse(true);
    CPPUNIT_ASSERT(info1.isInUse() == true);

    // unlock
    info1.setInUse(false);
    CPPUNIT_ASSERT(info1.isInUse() == false);

    test::printOut("\n\tAuto unlock ... ");

    // automatic unlock
    info1.setInUse(true);
    CPPUNIT_ASSERT(info1.isInUse() == true);
    sleep(2*LOCK_UPDATE_INTERVAL + 2);
    CPPUNIT_ASSERT(info1.isInUse() == false);

    // no automatic unlock
    info1.setInUse(true);
    CPPUNIT_ASSERT(info1.isInUse() == true);
    sleep(LOCK_UPDATE_INTERVAL);
    info1.updateInUse();
    CPPUNIT_ASSERT(info1.isInUse() == true);

    sleep(LOCK_UPDATE_INTERVAL);
    info1.updateInUse();
    CPPUNIT_ASSERT(info1.isInUse() == true);

    sleep(5);
    CPPUNIT_ASSERT(info1.isInUse() == true);

    test::printOut("\n\tClearing ... ");

    // final clearing
    info1.clearInUse();
    CPPUNIT_ASSERT(info1.isInUse() == false);
}