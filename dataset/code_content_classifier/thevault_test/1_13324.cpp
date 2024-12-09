void SocketTest::test2Connect()
{
    printOut("\nSocket (TCP/IP) exception test ... ");

    ThreadPtr thread(new ListenThread(sock::TCPIP));
    m_scheduler.addTestThread(thread);

    m_scheduler.start();
    sleep(5);

    // Test connection 2 times
    ISocketPtr sock = sock::Factory::getSocket(sock::TCPIP);
    sock::RouteInfo testroute(TESTSOCK_HOST, TESTSOCK_PORT,
                              sock::TCPIP, sock::UNICAST);
    Result rc = sock::Factory::checkConnection(testroute);
    CPPUNIT_ASSERT(rc == OK);
    sock->connect(testroute);
    sock->connect(testroute); // should produce exception ???
    m_scheduler.stop();
}