void ProtocolTest::test()
{
    test::printOut("\nSNMP protocol test ... ");

    CPPUNIT_ASSERT(!base::Utils::fileExist(SOCKTEST_NAME));

    test::ThreadPtr thread(new ProtocolTestThread());
    m_scheduler.addTestThread(thread);
    m_scheduler.start();

    // be sure that it has been started
    sleep(3);

    CPPUNIT_ASSERT(base::Utils::fileExist(SOCKTEST_NAME));

    // different tests
    testScalar();
    testTable();
    testScalar();
    testTable();
    testTable();

    sleep(2);
    m_scheduler.stop();
    m_scheduler.checkResult();
}