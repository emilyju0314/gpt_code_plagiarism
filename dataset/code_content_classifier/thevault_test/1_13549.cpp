void TestPlugin::setUp()
{
    // start only if we have a real device
    CPPUNIT_ASSERT(base::Utils::fileExist("/dev/dvb/adapter0") == 1);

    CPPUNIT_ASSERT(test::Factory::instance() != NULL);

    // reset test factory
    test::Factory::instance()->reset();

    // clear DB
    test::DBScriptLauncher launcher(test::Factory::instance()->getConfig());
    launcher.recreate();

    // set plugin as processor
    IFactory *factory = test::Factory::instance();
    IThreadFactoryPtr threadfactory(new getstream2::ThreadFactory(factory));
    m_dvbscheduler.setThreadFactory(threadfactory);

    // create dev
    createDev();

    // fillChannels
    fillChannels();
}