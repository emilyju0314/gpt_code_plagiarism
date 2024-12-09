void TestSNMP::updateDevInfo()
{
    IFactory* factory = test::Factory::instance();
    CPPUNIT_ASSERT(factory);

    IDevPtr dev1 = factory->getResources()->getResourceByName(TESTCARD1);
    CPPUNIT_ASSERT(dev1);
    dev1->setState(dev::WORK);
    dev1->setParam(dev::DVBACTIVITY, dev::STREAMING);
    dev1->setParam(dev::HASLOCK, "1");
    dev1->setParam(dev::SIGNAL, TEST_SIGNAL);
    dev1->setParam(dev::SNR, TEST_SNR);
    dev1->setParam(dev::UNC, TEST_UNC);
    dev1->setParam(dev::BER, TEST_BER);
    dev1->setParam(dev::RATE, TEST_RATE);
    IDevPtr dev2 = factory->getResources()->getResourceByName(TESTCARD2);
    CPPUNIT_ASSERT(dev2);
    dev2->setState(dev::WORK);
    dev2->setParam(dev::DVBACTIVITY, dev::STREAMING);
    dev2->setParam(dev::HASLOCK, "0");
    dev2->setParam(dev::SIGNAL, "0");
    dev2->setParam(dev::SNR, "0");
    dev2->setParam(dev::UNC, "0");
    dev2->setParam(dev::BER, "0");
    dev2->setParam(dev::RATE, 0);
}