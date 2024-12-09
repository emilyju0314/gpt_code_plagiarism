void TestPlugin::testOk()
{
    test::printOut("\nDVB Plugin test for correct tune ... ");

    startChannels();

    // sleep untill check will be done
    sleep(PLUGIN_UPDATEINFOINTERVAL + 50);

    // check dev state
    checkDev();

    // checks the channles
    checkChannels();

    // stop channels
    stopChannels();
}