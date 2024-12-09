void TestPlugin::testWrong()
{
    test::printOut("\nDVB Plugin test for incorrect tune ... ");

    // change frequency to wrong value
    getDev()->setParam(dev::FREQUENCY, "950001");

    startChannels(); // should produce exception
}