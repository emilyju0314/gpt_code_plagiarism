void TestSNMP::loadModules()
{
    Utils(test::Factory::instance()).addStation(TESTSTATION1, TESTROUTE1);
    Utils(test::Factory::instance()).addStation(TESTSTATION2, TESTROUTE2);

    TestBase::loadModules();
}