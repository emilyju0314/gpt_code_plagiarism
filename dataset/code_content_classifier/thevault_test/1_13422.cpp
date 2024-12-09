void TrapTest::testTraps()
{
    test::printOut("\nSNMP traps test ... ");

    IFactory *factory = test::Factory::instance();
    CPPUNIT_ASSERT(factory != NULL);

    ISNMP* snmp = factory->getSNMP();
    CPPUNIT_ASSERT(snmp);


    snmp->sendTrap(KLKTRAP_TEST, "teststring");
    snmp->sendTrap(KLKTRAP_TEST, 1234);


    sleep(5);

    // test traps
    test::TrapInfoVector result = m_receiver.getTraps();
    CPPUNIT_ASSERT(result.size() == 2);
    CPPUNIT_ASSERT(result[0].getValue() == "teststring");
    //CPPUNIT_NS::stdCOut() << "\nOid: " << result[0].getOID() << "\n";
    //CPPUNIT_NS::stdCOut().flush();
    CPPUNIT_ASSERT(result[0].getOID() == ".1.3.6.1.4.1.31106.2.1");
    CPPUNIT_ASSERT(test::IsOIDMatch()(result[0], KLKTRAP_TEST) == true);
    // matcher test
    CPPUNIT_ASSERT(test::IsOIDMatch()(result[0], snmp::MODULE_DNT_RESPONDE) ==
                   false);
    CPPUNIT_ASSERT(result[1].getValue() == "1234");
    CPPUNIT_ASSERT(result[1].getOID() == ".1.3.6.1.4.1.31106.2.1");
    CPPUNIT_ASSERT(test::IsOIDMatch()(result[1], KLKTRAP_TEST) == true);
}