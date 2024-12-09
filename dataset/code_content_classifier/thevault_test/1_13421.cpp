void TestStartup::test()
{
    test::printOut("\nHTTP Streamer startup test ... ");

    try
    {
        // check application uuid set
        CPPUNIT_ASSERT(getModule<Streamer>(MODID)->getAppUUID() ==
                       TESTAPPUUID);

        Factory* factory =
            getModule<Streamer>(MODID)->m_httpfactory;
        CPPUNIT_ASSERT(factory);

        // check output info
        OutThreadPtr outthread = factory->m_outthread;
        CPPUNIT_ASSERT(outthread);
        CPPUNIT_ASSERT(outthread->getRoute()->getHost() == TESTSERVERHOST);
        CPPUNIT_ASSERT(outthread->getRoute()->getPort() == TESTSERVERPORT);

        // check input info
        CPPUNIT_ASSERT(factory->m_inthreads);
        InThreadContainer::InThreadList list = factory->m_inthreads->m_list;
        CPPUNIT_ASSERT(list.size() == 2);
        bool was1 = false, was2 = false;
        for (InThreadContainer::InThreadList::iterator i = list.begin();
             i != list.end(); i++)
        {
            const InputInfoPtr info = (*i)->getInfo();
            CPPUNIT_ASSERT(info);
            CPPUNIT_ASSERT(info->getMediaTypeUuid() == TESTMTYPEUUID);

            if (info->getPath() == TESTPATH1)
            {
                CPPUNIT_ASSERT(was1 == false);
                CPPUNIT_ASSERT(info->getRouteInfo()->getHost() == TESTHOST1);
                CPPUNIT_ASSERT(info->getRouteInfo()->getPort() == TESTPORT1);
                was1 = true;
            }
            else if (info->getPath() == TESTPATH2)
            {
                CPPUNIT_ASSERT(was2 == false);
                CPPUNIT_ASSERT(info->getRouteInfo()->getHost() == TESTHOST2);
                CPPUNIT_ASSERT(info->getRouteInfo()->getPort() == TESTPORT2);
                was2 = true;
            }
            else
            {
                CPPUNIT_ASSERT(0);
            }
        }
        CPPUNIT_ASSERT(was1);
        CPPUNIT_ASSERT(was2);
    }
    catch(...)
    {
        m_scheduler.stop();
        throw;
    }
}